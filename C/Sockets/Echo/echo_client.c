#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1" /* Local host for testing purposes. */
#define	MESSAGE "Test message." /* Simplified for testing purposes. */
#define PORT 8080
#define BYTE_LIMIT 1024

/* This function handles errors during runtime. */
/* @param *error The error message. */
int	error_handling(const char *error)
{
	perror(error);
	return (-1);
}

int	connect_to_server(int cl_fd)
{
	struct sockaddr_in	sv_addr;
	memset(&sv_addr, 0, sizeof(sv_addr));
	sv_addr.sin_family = AF_INET;
	sv_addr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, SERVER_IP, &sv_addr.sin_addr) <= 0)
		return(error_handling("Invalid IP address.\n"));
	if (connect(cl_fd, (struct sockaddr *)&sv_addr, sizeof(sv_addr)) < 0)
		return(error_handling("Connection failed.\n"));
	return (1);
}

/* This function creates a socket. */
int	create_socket(void)
{
	int	cl_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (cl_fd < 0)
		return(error_handling("Failure to create socket.\n"));
	else
		return (cl_fd);
}

int	main()
{
	int		cl_fd;
	void	*buf;

	buf = malloc(BYTE_LIMIT);
	if (!buf)
		return(error_handling("Memory error.\n"));
	cl_fd = create_socket();
	if (cl_fd < 0)
		return (-1);
	if (connect_to_server(cl_fd) < 0)
		return (-1);
	printf("Connection successful.\n");
	send(cl_fd, MESSAGE, strlen(MESSAGE), 0);
	recv(cl_fd, buf, BYTE_LIMIT, 0);
	printf("Server: %s\n", (char *) buf);
	free(buf);
	close(cl_fd);
	return (0);
}