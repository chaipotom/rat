#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
//       ssize_t read(size_t count; int fd, void buf[count], size_t count);

int main() {
	char *filename = "test.txt";
	printf("Reading %s\n", filename);

	int fd = open(filename, O_RDONLY);

	unsigned long word;
	ssize_t nr;

	nr = read(fd, &word, sizeof(unsigned long));
	if (nr == -1) {
		fprintf(stderr, "Error occured while reading file\n");
		return 1;
	}

	printf("%ld bytes is read\n", nr);
	printf("%ld\n", word);

	close(fd);

	return 0;
}

