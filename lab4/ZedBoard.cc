class ZedBoard{
      char *ptr;
      int fd;
public:
       ZedBoard(int *fd,unsigned gpio_size,unsigned gpio_address){
           *fd = open("/dev/mem", O_RDWR);
           ptr = (char *)mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED,*fd, gpio_address);
       }
       ~ZedBoard(){
           munmap(ptr, gpio_size);
           close(fd);
       }
       void RegisterWrite(int offset, int value){
            *(int *)(ptr + offset) = value;
       }
       int RegisterRead(int offset){
           return *(int *)(ptr + offset);
       }
}