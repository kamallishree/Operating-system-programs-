#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int source, dest, n;
    char buffer[100];
    source = open("source.txt", O_RDONLY);
    if (source < 0) {
        source = open("source.txt", O_WRONLY | O_CREAT, 0644);
        write(source, "Sample Data\n", 12);
        close(source);
        source = open("source.txt", O_RDONLY);
    }
    dest = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((n = read(source, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, n);
    }
    close(source);
    close(dest);
    printf("File copied successfully!\n");
    return 0;
}
