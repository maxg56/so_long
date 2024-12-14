valgrind ./so_long  maps/maps.ber             
==1444857== Memcheck, a memory error detector
==1444857== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1444857== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1444857== Command: ./so_long maps/maps.ber
==1444857== 
flag parsed
map 1
1111111111111111111111111111
1P0000000000CC00000000000001
1000000000000000000000000001
1000000000000000000000000E01
1000000000000000000000000001
1000000000000000000000000001
1111111111111111111111111111
1111111111111111111111111111
1P0000000000CC00000000000001
1000000000000000000000000001
1000000000000000000000000E01
1000000000000000000000000001
1000000000000000000000000001
1111111111111111111111111111
==1444857== Warning: noted but unhandled ioctl 0x644f with no size/direction hints.
==1444857==    This could cause spurious value errors to appear.
==1444857==    See README_MISSING_SYSCALL_OR_IOCTL for guidance on writing a proper wrapper.
==1444857== Warning: noted but unhandled ioctl 0x6444 with no size/direction hints.
==1444857==    This could cause spurious value errors to appear.
==1444857==    See README_MISSING_SYSCALL_OR_IOCTL for guidance on writing a proper wrapper.
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
==1444857== Invalid read of size 8
==1444857==    at 0x403F50: free_game (free.c:38)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1b8 is 8 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F5F: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1b8 is 8 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E00: free_map (free.c:17)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e220 is 0 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E0E: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e220 is 0 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403EAB: free_tab (free.c:56)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8fd70 is 0 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403EDD: free_tab (free.c:61)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4069E2: ft_split (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x40500D: open_and_check_map (parsing.c:69)
==1444857==    by 0x4028ED: main (main.c:104)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403EBE: free_tab (free.c:58)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8fd70 is 0 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403EDD: free_tab (free.c:61)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4069E2: ft_split (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x40500D: open_and_check_map (parsing.c:69)
==1444857==    by 0x4028ED: main (main.c:104)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403EC6: free_tab (free.c:58)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8fdf0 is 0 bytes inside a block of size 29 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403EC6: free_tab (free.c:58)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x407045: ft_substr (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x406A7C: ft_split (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x40500D: open_and_check_map (parsing.c:69)
==1444857==    by 0x4028ED: main (main.c:104)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403EDD: free_tab (free.c:61)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8fd70 is 0 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403EDD: free_tab (free.c:61)
==1444857==    by 0x403E15: free_map (free.c:18)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4069E2: ft_split (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x40500D: open_and_check_map (parsing.c:69)
==1444857==    by 0x4028ED: main (main.c:104)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E1A: free_map (free.c:19)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e258 is 56 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E22: free_map (free.c:19)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d907f0 is 0 bytes inside a block of size 12 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E22: free_map (free.c:19)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404441: init_map_info (init.c:71)
==1444857==    by 0x402D34: check_path (check_map.c:122)
==1444857==    by 0x405080: open_and_check_map (parsing.c:74)
==1444857==    by 0x4028ED: main (main.c:104)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E27: free_map (free.c:20)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e230 is 16 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E2F: free_map (free.c:20)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e2f0 is 0 bytes inside a block of size 128 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E2F: free_map (free.c:20)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4047F1: init_sprite_map (sprite_usils.c:19)
==1444857==    by 0x4043C3: init_map (init.c:26)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E34: free_map (free.c:21)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e238 is 24 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E3C: free_map (free.c:21)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e8b0 is 0 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E3C: free_map (free.c:21)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404911: init_sprite (sprite_usils.c:43)
==1444857==    by 0x4043D3: init_map (init.c:27)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E41: free_map (free.c:22)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e240 is 32 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E49: free_map (free.c:22)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e900 is 0 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E49: free_map (free.c:22)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404911: init_sprite (sprite_usils.c:43)
==1444857==    by 0x4043E3: init_map (init.c:28)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E4E: free_map (free.c:23)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e248 is 40 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E56: free_map (free.c:23)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e950 is 0 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E56: free_map (free.c:23)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404911: init_sprite (sprite_usils.c:43)
==1444857==    by 0x4043F3: init_map (init.c:29)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403E5B: free_map (free.c:24)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e250 is 48 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E63: free_map (free.c:24)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e9a0 is 0 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E63: free_map (free.c:24)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404911: init_sprite (sprite_usils.c:43)
==1444857==    by 0x404403: init_map (init.c:30)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e220 is 0 bytes inside a block of size 64 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403E6C: free_map (free.c:25)
==1444857==    by 0x403F67: free_game (free.c:39)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404371: init_map (init.c:19)
==1444857==    by 0x404DCD: init_game (window.c:39)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F6C: free_game (free.c:40)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1c0 is 16 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F7B: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1c0 is 16 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F00: free_player (free.c:30)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e9f0 is 0 bytes inside a block of size 24 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F2B: free_player (free.c:33)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404507: init_player (init.c:51)
==1444857==    by 0x404DEC: init_game (window.c:41)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F0E: free_player (free.c:31)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e9f0 is 0 bytes inside a block of size 24 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F2B: free_player (free.c:33)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404507: init_player (init.c:51)
==1444857==    by 0x404DEC: init_game (window.c:41)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F15: free_player (free.c:31)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8ea50 is 0 bytes inside a block of size 12 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F15: free_player (free.c:31)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4044A1: init_point (init.c:38)
==1444857==    by 0x404528: init_player (init.c:54)
==1444857==    by 0x404DEC: init_game (window.c:41)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F1A: free_player (free.c:32)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8ea00 is 16 bytes inside a block of size 24 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F2B: free_player (free.c:33)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404507: init_player (init.c:51)
==1444857==    by 0x404DEC: init_game (window.c:41)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F22: free_player (free.c:32)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8eaa0 is 0 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F22: free_player (free.c:32)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404911: init_sprite (sprite_usils.c:43)
==1444857==    by 0x40458A: init_player (init.c:61)
==1444857==    by 0x404DEC: init_game (window.c:41)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F2B: free_player (free.c:33)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e9f0 is 0 bytes inside a block of size 24 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F2B: free_player (free.c:33)
==1444857==    by 0x403F83: free_game (free.c:41)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404507: init_player (init.c:51)
==1444857==    by 0x404DEC: init_game (window.c:41)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F88: free_game (free.c:42)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1b0 is 0 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403F96: free_game (free.c:43)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1b0 is 0 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F9D: free_game (free.c:43)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d90840 is 0 bytes inside a block of size 24 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403F9D: free_game (free.c:43)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404CEB: init_window (window.c:19)
==1444857==    by 0x4027BC: lood_game (main.c:73)
==1444857==    by 0x40291D: main (main.c:107)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403FA2: free_game (free.c:44)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1c8 is 24 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x403FB1: free_game (free.c:45)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1c8 is 24 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid read of size 8
==1444857==    at 0x4045D3: free_int_list (usils_list_int.c:22)
==1444857==    by 0x403FB9: free_game (free.c:45)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8eaf8 is 8 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4045E3: free_int_list (usils_list_int.c:23)
==1444857==    by 0x403FB9: free_game (free.c:45)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404601: init_int_list (usils_list_int.c:31)
==1444857==    by 0x404E21: init_game (window.c:44)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4045E3: free_int_list (usils_list_int.c:23)
==1444857==    by 0x403FB9: free_game (free.c:45)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8eaf0 is 0 bytes inside a block of size 16 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x4045E3: free_int_list (usils_list_int.c:23)
==1444857==    by 0x403FB9: free_game (free.c:45)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404601: init_int_list (usils_list_int.c:31)
==1444857==    by 0x404E21: init_game (window.c:44)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== Invalid free() / delete / delete[] / realloc()
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404089: free_init_game (free.c:81)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Address 0x4d8e1b0 is 0 bytes inside a block of size 40 free'd
==1444857==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x403FC2: free_game (free.c:46)
==1444857==    by 0x404017: free_init_game (free.c:70)
==1444857==    by 0x40421C: exit_game (Erore.c:49)
==1444857==    by 0x402538: ft_hook (main.c:28)
==1444857==    by 0x4089D5: mlx_loop (in /home/mgendrot/Documents/so_long/so_long)
==1444857==    by 0x402987: main (main.c:111)
==1444857==  Block was alloc'd at
==1444857==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1444857==    by 0x404DA1: init_game (window.c:35)
==1444857==    by 0x40556B: parse_flag (parsimg_flag.c:56)
==1444857==    by 0x4028A8: main (main.c:100)
==1444857== 
==1444857== 
==1444857== HEAP SUMMARY:
==1444857==     in use at exit: 66,327 bytes in 926 blocks
==1444857==   total heap usage: 21,287 allocs, 20,394 frees, 537,145,420 bytes allocated
==1444857== 
==1444857== LEAK SUMMARY:
==1444857==    definitely lost: 280 bytes in 18 blocks
==1444857==    indirectly lost: 0 bytes in 0 blocks
==1444857==      possibly lost: 0 bytes in 0 blocks
==1444857==    still reachable: 0 bytes in 0 blocks
==1444857==         suppressed: 66,047 bytes in 908 blocks
==1444857== Rerun with --leak-check=full to see details of leaked memory
==1444857== 
==1444857== For lists of detected and suppressed errors, rerun with: -s
==1444857== ERROR SUMMARY: 80 errors from 37 contexts (suppressed: 0 from 0)