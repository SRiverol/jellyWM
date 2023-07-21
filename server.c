#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wayland-server.h>

struct jellyWM
{
	struct wl_display *display; 
  struct wl_event_loop *wl_event_loop;
	const char *socket;
};

int main()
{
	struct jellyWM server;

	// Starts display
	server.display = wl_display_create();
	if (!server.display)
	{
		fprintf(stderr, "Unable to create wayland display\n");
		return -1;
	}
	//Binds socket to display to be used by clients 
	server.socket = wl_display_add_socket_auto(server.display);
	if (!server.socket)
	{
		fprintf(stderr, "Unable to create socket %s\n", server.socket);
		return -1;
	}
	fprintf(stderr, "Started wayland server on socket %s", server.socket);
  
	wl_display_run(server.display);
  
	

	wl_display_destroy(server.display);
	return 1;
}
