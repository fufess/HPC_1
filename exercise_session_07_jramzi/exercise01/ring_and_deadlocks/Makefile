ring_synchronous	: ring_synchronous.c
	cc -O3 -ffast-math -o ring_synchronous ring_synchronous.c
ring_nonblocking_rsw    : ring_nonblocking_rsw.c
	cc -O3 -ffast-math -o ring_nonblocking_rsw ring_nonblocking_rsw.c
ring_nonblocking_srw    : ring_nonblocking_srw.c
	cc -O3 -ffast-math -o ring_nonblocking_srw ring_nonblocking_srw.c
all			: ring_synchronous ring_nonblocking_rsw ring_nonblocking_srw

clean			:
	rm -f ring_synchronous ring_nonblocking_rsw ring_nonblocking_srw
