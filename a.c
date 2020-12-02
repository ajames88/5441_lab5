#include <mpi.h>
#include <stdio.h>
#include <time.h>

int main (int argc, char *argv[]) {

    time_t start_time;
    time_t end_time;

    int numIterations = 20;

    int rank;
    int msg;

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    time(&start_time);

    for (int i = 0; i < numIterations; ++i) {

        // process 0 sending to process 1
        if (rank == 0) {

            msg = 42;
            MPI_Send(&msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        } 
        else {
            // process 0 recieveing from process 1
            if (rank == 1) {
            MPI_Recv(&msg, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
            printf("Received %d\n", msg);
        }

    }

    time(&end_time);
    double time = ((end_time - start_time) / 4.0 * numIterations);
    double bandwidth = (sizeof(double) * sizeof(int)) / time;

    MPI_Finalize();

    return(0);

}