Initialize MPI
int MPI_Init(int *argc, char **argv)

Determine number of processes within  a communicator
int MPI_Comm_size(MPI_Comm comm, int *size)

Determine processor rank within a communicator
int MPI_Comm_rank(MPI_Comm comm, int *rank)

Exit MPI (must be called last by all processors)
int MPI_Finalize()

Send a message
int MPI_Send (void *buf,int count, MPI_Datatype
datatype, int dest, int tag, MPI_Comm comm)

Receive a message
int MPI_Recv (void *buf,int count, MPI_Datatype
datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
