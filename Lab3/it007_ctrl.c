#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t child_pid;  // Biến toàn cục để lưu PID của tiến trình con (vim)

void handle_sigint(int sig) {
    printf("\nYou are pressed CTRL+C! Goodbye!\n");
    if (child_pid > 0) {
        kill(child_pid, SIGTERM); // Gửi tín hiệu kết thúc vim
        wait(NULL);               // Chờ tiến trình con kết thúc
    }
    exit(0);
}

int main() {
    // a. In thông báo
    printf("Welcome to IT007, I am Phuc Minh - 23520930!\n");

    // b. Đăng ký hàm xử lý tín hiệu SIGINT (CTRL+C)
    signal(SIGINT, handle_sigint);

    // c. Tạo tiến trình con để chạy vim
    child_pid = fork();
    if (child_pid == 0) {
        // Trong tiến trình con → mở vim với abcd.txt
        execlp("vim", "vim", "abcd.txt", NULL);
        perror("execlp failed"); // Nếu lỗi
        exit(1);
    } else if (child_pid > 0) {
        // Trong tiến trình cha → chờ CTRL+C hoặc con kết thúc
        wait(NULL);  // Đợi tiến trình vim kết thúc
    } else {
        perror("fork failed");
        return 1;
    }

    return 0;
}
