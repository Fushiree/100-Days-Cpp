// Đảo ngược từng hàng trong mảng hai chiều
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hàm khởi tạo và in mảng hai chiều với các giá trị ngẫu nhiên
void inmangngaunhien(int arr[100][100], int sohang, int socot){
    // Khởi tạo các phần tử ngẫu nhiên trong mảng
    for(int i = 0; i < sohang; ++i){
        for(int j = 0; j < socot; ++j){
            arr[i][j] = rand() % 100;  // Tạo phần tử ngẫu nhiên trong khoảng từ 0 đến 99
        }
    }

    // In mảng ban đầu
    cout << "Mang ban dau la: " << endl;
    for(int i = 0; i < sohang; ++i){
        for(int j = 0; j < socot; ++j){
            cout << "[" << arr[i][j] << "]";  // In từng phần tử của mảng với định dạng [giá trị]
        }
        cout << endl;  // Xuống dòng sau khi in hết các phần tử của một hàng
    }
    cout << endl;
}

// Hàm đảo ngược từng hàng của mảng hai chiều
void daonguochangmang(int arr[100][100], int sohang, int socot){
    for(int i = 0; i < sohang; ++i){
        int start = 0;
        int end = socot - 1;

        // Sử dụng vòng lặp để hoán đổi các phần tử từ hai đầu hàng tiến về giữa
        while(start < end){
            int temp = arr[i][start];  // Lưu trữ tạm thời giá trị của phần tử tại chỉ số start
            arr[i][start] = arr[i][end];  // Gán giá trị của phần tử tại chỉ số end cho phần tử tại chỉ số start
            arr[i][end] = temp;  // Gán giá trị lưu trong temp cho phần tử tại chỉ số end
            start++;
            end--;
        }
    }
}

// Hàm in mảng sau khi đã đảo ngược từng hàng
void inmangdaonguoc(int arr[100][100], int sohang, int socot){
    cout << "Mang sau khi dao nguoc: " << endl;
    for(int i = 0; i < sohang; ++i){
        for(int j = 0; j < socot; ++j){
            cout << "[" << arr[i][j] << "]";  // In từng phần tử của mảng sau khi đã đảo ngược với định dạng [giá trị]
        }
        cout << endl;  // Xuống dòng sau khi in hết các phần tử của một hàng
    }
}

int main(){
    srand(static_cast<unsigned int>(time(0)));  // Khởi tạo seed cho hàm rand()

    int sohang, socot;
    cout << "Hay nhap so hang va so cot cua mang: ";
    cin >> sohang >> socot;
    int arr[100][100];  // Khai báo mảng hai chiều với kích thước tối đa

    inmangngaunhien(arr, sohang, socot);  // Gọi hàm khởi tạo và in mảng ban đầu
    daonguochangmang(arr, sohang, socot);  // Gọi hàm đảo ngược từng hàng của mảng
    inmangdaonguoc(arr, sohang, socot);  // Gọi hàm in mảng sau khi đảo ngược

    return 0;
}