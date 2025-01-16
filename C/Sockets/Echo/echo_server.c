#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BYTE_LIMIT 1024

/* This function handles errors during runtime. */
/* @param *error The error message. */
int	error_handling(const char *error)
{
	perror(error);
	return (-1);
}

/* This function creates a socket. */
int	create_socket(void)
{
	int opt = 1;
	int	sv_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sv_fd < 0)
		return(error_handling("Failure to create socket.\n"));
    if (setsockopt(sv_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		return error_handling("setsockopt(SO_REUSEADDR) failed.\n");
	return (sv_fd);
}

/* This function binds an IP address to the socket created by the server. */
/* @param *sv_fd The file descriptor of the socket. */
int	bind_address(int *sv_fd)
{
	struct sockaddr_in sv_addr;

	memset(&sv_addr, 0, sizeof(sv_addr));
	sv_addr.sin_family = AF_INET;
	sv_addr.sin_port = htons(PORT);
	sv_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(*sv_fd, (struct sockaddr *)&sv_addr, sizeof(sv_addr)) < 0)
		return (error_handling("Failure binding socket.\n"));
	else
		return (1);
}

int	main()
{
	int					sv_fd;
	int					cl_fd;
	struct sockaddr_in	cl_addr;
	socklen_t			cl_len = sizeof(cl_addr);
	void				*buf;

	buf = malloc(BYTE_LIMIT);
	if (!buf)
		return(error_handling("Memory error.\n"));
	sv_fd = create_socket();
	if (sv_fd < 0)
		return (-1);
	if (bind_address(&sv_fd) < 0)
		return (-1);
	if (listen(sv_fd, 5) < 0)
		return (error_handling("Listen failed.\n"));
	printf("The server is now listening on port %i. \n", PORT);
	cl_fd = accept(sv_fd, (struct sockaddr *)&cl_addr, &cl_len);
	if (cl_fd < 0)
		return (error_handling("Failure accepting connection.\n"));
	printf("Connection made with %s:%d\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));
	recv(cl_fd, buf, BYTE_LIMIT, 0);
	printf("Client: %s\n", (char *) buf);
	send(cl_fd, buf, strlen(buf), 0);
	free(buf);
	close(cl_fd);
	shutdown(sv_fd, SHUT_RDWR);
	close(sv_fd);
	return (0);
}