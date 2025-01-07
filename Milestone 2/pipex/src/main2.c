#include "../includes/utils.h"

// gcc src/main.c src/utils.c includes/utils.h -o m1 && gcc src/main2.c src/utils.c includes/utils.h -o m2

int	main(int ac, char **av)
{
	int		fd;
	int		arr[5];
	int		i;
	int		rb;
	int		sum;

	if (!ac && !av)
		return (1);
	// Read Numbers from Fifo
	fd = open("fifoData", O_RDONLY);
	if (fd == -1)
		printf("Error in opening file");
	i = 0;
	while ((rb = read(fd, &arr[i], sizeof(int))))
	{
		if (rb == -1)
			printf("Error in reading file");
        sum += arr[i];
		i++;
	}
	close(fd);

	// Write Sum Numbers to Fifo
    fd = open("fifoData", O_WRONLY);
	if (fd == -1)
		printf("Error in opening file");
    if (write(fd, &sum, sizeof(arr[i])) == -1)
			printf("Error in writing file");
	close(fd);
	return (0);
}