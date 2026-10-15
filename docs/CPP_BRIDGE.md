# Bắt đầu C++ khi đã biết Python

**Đọc trang này để biết cách thử code; đọc [Stage 1 của CONCEPTS.md](CONCEPTS.md) để hiểu từng khái niệm.** Chưa cần học cả bảy stage.

## 1. Một chương trình C++ chạy riêng có hình dạng gì?

```cpp
#include <iostream>

int main() {
    int number = 5;
    std::cout << number << '\n';
    return 0;
}
```

- include cho phép dùng thành phần thư viện tương ứng; iostream cung cấp cout.
- main là nơi chương trình bắt đầu chạy.
- int đứng trước tên biến để khai báo số nguyên.
- cout gửi dữ liệu ra terminal; '\n' là ký tự xuống dòng.
- return 0 từ main báo chương trình kết thúc thành công.

Trong Python bạn thường chạy file .py trực tiếp bằng Python. Với C++, trước hết compiler dịch code thành executable, rồi bạn chạy executable đó.

## 2. Thử ví dụ đã có sẵn trong repo

Mở [python_bridge.cpp](examples/python_bridge.cpp). Chương trình này minh họa copy, reference và optional; nó không phải lời giải bài 01.

Từ thư mục gốc repo, trong terminal WSL:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic docs/examples/python_bridge.cpp -o build/python_bridge
./build/python_bridge
```

Kết quả:

```text
After copy: 5
After reference: 6
First negative: -2
Optional contains: 0
```

Đọc cùng Stage 1 của CONCEPTS.md, rồi thử tự thay đổi input:

- Đổi vector thành {4, 2, 0}: nhánh nào chạy khi không có số âm?
- Đổi number ban đầu thành 10: hai dòng đầu sẽ in gì?
- Vì sao optional chứa số 0 vẫn chạy vào if?

Nếu sửa code, cần compile lại trước khi chạy để executable chứa phiên bản mới.

## 3. Làm bài trong repo thì khác gì?

Mỗi bài có bốn file:

| File | Việc của bạn |
| --- | --- |
| README.md | Đọc yêu cầu, ví dụ và hint khi cần |
| starter.hpp | Viết hàm/class của bạn |
| test.cpp | Đọc các tình huống kiểm tra, có thể thêm case |
| solution.hpp | Chỉ mở sau khi đã thử hoặc cần đối chiếu |

starter đã có include và chữ ký hàm. Bạn điền phần thân hàm; **không thêm main vào starter**, vì test.cpp đã có main. Runner compile và chạy test cho bạn:

```bash
python3 tools/run.py 01
```

Ban đầu, TODO có chủ đích ném exception để báo bạn chưa triển khai. Đó không phải lỗi cài đặt.

## 4. Đọc thông báo lỗi theo loại

| Tình huống | Ý nghĩa |
| --- | --- |
| Compiler báo error | Code chưa dịch được: kiểm tra cú pháp, dấu chấm phẩy, tên biến và kiểu |
| Compile được nhưng CHECK fail | Chương trình chạy nhưng kết quả sai với case được kiểm tra |
| Uncaught exception: TODO | Bạn chưa thay phần placeholder, hoặc còn gọi đến placeholder |
| Chạy binary vẫn ra kết quả cũ | Có thể bạn chưa compile lại sau khi sửa |

Nếu chữ ký dài làm bạn khó đọc, đừng cố hiểu cả dòng một lượt. Tách kiểu trả về → tên hàm → từng tham số; Stage 1 giải thích cách làm này.

## Tiếp theo

Sau khi hiểu copy/reference/optional ở Stage 1, thử bài 01. Đến Stage 2 mới đọc thêm string_view và iterator; đến Stage 4 mới học pointer/ownership. Không cần thuộc trước toàn bộ thuật ngữ C++ mới bắt đầu giải bài.
