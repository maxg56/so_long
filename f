==1464471== Invalid read of size 8
==1464471==    at 0x403F40: free_game (free.c:38)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1b8 is 8 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403F4F: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1b8 is 8 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403DF0: free_map (free.c:17)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e220 is 0 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403E0A: free_map (free.c:19)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e258 is 56 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E12: free_map (free.c:19)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e2a0 is 0 bytes inside a block of size 12 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E12: free_map (free.c:19)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404401: init_map_info (init.c:71)
==1464471==    by 0x40435D: init_map (init.c:23)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403E17: free_map (free.c:20)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e230 is 16 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E1F: free_map (free.c:20)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e2f0 is 0 bytes inside a block of size 128 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E1F: free_map (free.c:20)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4047B1: init_sprite_map (sprite_usils.c:19)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403E24: free_map (free.c:21)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e238 is 24 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E2C: free_map (free.c:21)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e8b0 is 0 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E2C: free_map (free.c:21)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404393: init_map (init.c:27)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403E31: free_map (free.c:22)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e240 is 32 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E39: free_map (free.c:22)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e900 is 0 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E39: free_map (free.c:22)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4043A3: init_map (init.c:28)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403E3E: free_map (free.c:23)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e248 is 40 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E46: free_map (free.c:23)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e950 is 0 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E46: free_map (free.c:23)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4043B3: init_map (init.c:29)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403E4B: free_map (free.c:24)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e250 is 48 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E53: free_map (free.c:24)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e9a0 is 0 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E53: free_map (free.c:24)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4043C3: init_map (init.c:30)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e220 is 0 bytes inside a block of size 64 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403E5C: free_map (free.c:25)
==1464471==    by 0x403F57: free_game (free.c:39)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404331: init_map (init.c:19)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403F5C: free_game (free.c:40)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1c0 is 16 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403F6B: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1c0 is 16 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403EF0: free_player (free.c:30)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e9f0 is 0 bytes inside a block of size 24 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F1B: free_player (free.c:33)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4044C7: init_player (init.c:51)
==1464471==    by 0x404DAC: init_game (window.c:41)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403EFE: free_player (free.c:31)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e9f0 is 0 bytes inside a block of size 24 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F1B: free_player (free.c:33)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4044C7: init_player (init.c:51)
==1464471==    by 0x404DAC: init_game (window.c:41)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F05: free_player (free.c:31)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8ea50 is 0 bytes inside a block of size 12 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F05: free_player (free.c:31)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404461: init_point (init.c:38)
==1464471==    by 0x4044E8: init_player (init.c:54)
==1464471==    by 0x404DAC: init_game (window.c:41)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403F0A: free_player (free.c:32)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8ea00 is 16 bytes inside a block of size 24 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F1B: free_player (free.c:33)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4044C7: init_player (init.c:51)
==1464471==    by 0x404DAC: init_game (window.c:41)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F12: free_player (free.c:32)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8eaa0 is 0 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F12: free_player (free.c:32)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x40454A: init_player (init.c:61)
==1464471==    by 0x404DAC: init_game (window.c:41)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F1B: free_player (free.c:33)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e9f0 is 0 bytes inside a block of size 24 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403F1B: free_player (free.c:33)
==1464471==    by 0x403F73: free_game (free.c:41)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4044C7: init_player (init.c:51)
==1464471==    by 0x404DAC: init_game (window.c:41)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403F78: free_game (free.c:42)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1b0 is 0 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403F92: free_game (free.c:44)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1c8 is 24 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x403FA1: free_game (free.c:45)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1c8 is 24 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid read of size 8
==1464471==    at 0x404593: free_int_list (usils_list_int.c:22)
==1464471==    by 0x403FA9: free_game (free.c:45)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8eaf8 is 8 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4045A3: free_int_list (usils_list_int.c:23)
==1464471==    by 0x403FA9: free_game (free.c:45)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4045C1: init_int_list (usils_list_int.c:31)
==1464471==    by 0x404DE1: init_game (window.c:44)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4045A3: free_int_list (usils_list_int.c:23)
==1464471==    by 0x403FA9: free_game (free.c:45)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8eaf0 is 0 bytes inside a block of size 16 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4045A3: free_int_list (usils_list_int.c:23)
==1464471==    by 0x403FA9: free_game (free.c:45)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4045C1: init_int_list (usils_list_int.c:31)
==1464471==    by 0x404DE1: init_game (window.c:44)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== Invalid free() / delete / delete[] / realloc()
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x404007: free_init_game (free.c:70)
==1464471==    by 0x4040D8: exit_error (Erore.c:21)
==1464471==    by 0x402903: main (main.c:103)
==1464471==  Address 0x4d8e1b0 is 0 bytes inside a block of size 40 free'd
==1464471==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x403FB2: free_game (free.c:46)
==1464471==    by 0x40412D: error (Erore.c:29)
==1464471==    by 0x404FB3: open_and_check_map (parsing.c:69)
==1464471==    by 0x4028ED: main (main.c:102)
==1464471==  Block was alloc'd at
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x404D61: init_game (window.c:35)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 
==1464471== HEAP SUMMARY:
==1464471==     in use at exit: 256 bytes in 16 blocks
==1464471==   total heap usage: 34 allocs, 30 frees, 729 bytes allocated
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 1 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4047BA: init_sprite_map (sprite_usils.c:20)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 2 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4047C9: init_sprite_map (sprite_usils.c:21)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 3 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4047D9: init_sprite_map (sprite_usils.c:22)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 4 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4047E9: init_sprite_map (sprite_usils.c:23)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 5 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4047F9: init_sprite_map (sprite_usils.c:24)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 6 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404809: init_sprite_map (sprite_usils.c:25)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 7 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404819: init_sprite_map (sprite_usils.c:26)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 8 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404829: init_sprite_map (sprite_usils.c:27)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 9 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404839: init_sprite_map (sprite_usils.c:28)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 10 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404849: init_sprite_map (sprite_usils.c:29)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 11 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404859: init_sprite_map (sprite_usils.c:30)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 12 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404869: init_sprite_map (sprite_usils.c:31)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 13 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404879: init_sprite_map (sprite_usils.c:32)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 14 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404889: init_sprite_map (sprite_usils.c:33)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 15 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x404899: init_sprite_map (sprite_usils.c:34)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== 16 bytes in 1 blocks are definitely lost in loss record 16 of 16
==1464471==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1464471==    by 0x4048D1: init_sprite (sprite_usils.c:43)
==1464471==    by 0x4048A9: init_sprite_map (sprite_usils.c:35)
==1464471==    by 0x404383: init_map (init.c:26)
==1464471==    by 0x404D8D: init_game (window.c:39)
==1464471==    by 0x40555B: parse_flag (parsimg_flag.c:56)
==1464471==    by 0x4028A8: main (main.c:98)
==1464471== 
==1464471== LEAK SUMMARY:
==1464471==    definitely lost: 256 bytes in 16 blocks
==1464471==    indirectly lost: 0 bytes in 0 blocks
==1464471==      possibly lost: 0 bytes in 0 blocks
==1464471==    still reachable: 0 bytes in 0 blocks
==1464471==         suppressed: 0 bytes in 0 blocks
==1464471== 
==1464471== For lists of detected and suppressed errors, rerun with: -s
==1464471== ERROR SUMMARY: 46 errors from 46 contexts (suppressed: 0 from 0)
