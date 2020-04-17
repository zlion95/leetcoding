# leetcoding
Welcome to my leetcoding project. Here, I will present some solutions for leetcode problems.

## How to use
You can use the simple Makefile to compile all cpp source files with one comman.

```bash
    $ make
```

When you add some new test case, you can add it to ./test_case, and use following command to run test case.

```bash
    $ cat ./test_case/qxx_case1 | ./qxx_xxx.out
```

##NOTE
Please add don't sync iostream when push to leetcode.

```c++
	static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
```
