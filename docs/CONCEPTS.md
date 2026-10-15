# Hiểu C++ từ những gì bạn đã biết trong Python

Bạn không cần đọc hết trang này trước khi làm bài 01. **Hiện tại, chỉ đọc Stage 1 và thử các ví dụ của Stage 1.** Đến nhóm bài nào mới đọc tiếp phần đó.

Mỗi phần đi theo thứ tự: ý tưởng quen thuộc trong Python → cách viết trong C++ → ý nghĩa của ký hiệu → điều cần hiểu để làm bài. Ví dụ minh họa dùng bài toán nhỏ, không phải lời giải bài tập.

## Trước hết: đọc một dòng C++ như thế nào?

Python:

```python
numbers = [4, 7, 2]
numbers.append(9)
```

C++:

```cpp
std::vector<int> numbers{4, 7, 2};
numbers.push_back(9);
```

Đọc từng phần:

| Cú pháp | Ý nghĩa ở đây |
| --- | --- |
| `std::` | Tên đứng sau thuộc thư viện chuẩn C++ |
| `vector` | Một dãy có thể thêm/bớt phần tử, gần với list ở cách sử dụng |
| `<int>` | Các phần tử của dãy này có kiểu int |
| `numbers` | Tên biến |
| `{4, 7, 2}` | Các giá trị ban đầu |
| `;` | Kết thúc câu lệnh |
| `.push_back(9)` | Thêm 9 vào cuối dãy |

`vector<int>` không hoàn toàn giống list: nó chứa các phần tử cùng kiểu và có các quy tắc về bộ nhớ mà mình sẽ học sau. Lúc bắt đầu, hãy dùng nó như một dãy số nguyên.

Các đoạn ngắn bên dưới thường là **phần nằm trong một hàm**. Muốn chạy riêng, xem khung chương trình trong [CPP_BRIDGE.md](CPP_BRIDGE.md). Khi làm bài trong repo, không thêm main vì test đã có sẵn.

## Stage 1 — Đủ để bắt đầu bài 01–04

### 1. Kiểu dữ liệu: C++ muốn biết biến chứa loại gì

Python:

```python
count = 3
average = 2.5
```

C++:

```cpp
int count = 3;
double average = 2.5;
```

- `int`: số nguyên, có thể âm.
- `double`: số thực.
- `bool`: true hoặc false.
- `std::string`: chuỗi.

Python cho phép một tên biến được gán sang object kiểu khác. Trong C++, kiểu của biến đã được xác định khi khai báo.

```cpp
auto count = 3;  // Compiler suy ra count là int.
```

`auto` chỉ giúp khỏi viết tên kiểu dài; count vẫn là int. Nó không biến C++ thành ngôn ngữ có kiểu động.

Một khác biệt đáng chú ý:

```cpp
int a = 5 / 2;        // 2: chia hai số nguyên.
double b = 5.0 / 2;   // 2.5: có toán hạng số thực.
```

Để lấy chiều dài vector, dùng `numbers.size()`. Kết quả có kiểu `std::size_t`, dùng cho kích thước và không biểu diễn số âm. Chưa cần nhớ hết quy tắc số học của nó; trước mắt, đừng trừ 1 khỏi kích thước 0 rồi dùng làm chỉ số.

### 2. Duyệt vector giống for trong Python

Python:

```python
for number in numbers:
    if number > 5:
        print(number)
```

C++:

```cpp
for (int number : numbers) {
    if (number > 5) {
        std::cout << number << '\n';
    }
}
```

`int number : numbers` nghĩa là lần lượt lấy từng phần tử vào biến number. `{ ... }` gom các câu lệnh của vòng lặp hoặc nhánh if, thay cho vai trò của thụt lề trong Python. Bạn vẫn nên thụt lề để dễ đọc.

| Python | C++ |
| --- | --- |
| `and` | `&&` |
| `or` | `||` |
| `not` | `!` |
| `True`, `False` | `true`, `false` |
| `len(numbers)` | `numbers.size()` |
| `numbers.append(x)` | `numbers.push_back(x)` |

### 3. Đọc chữ ký hàm: kiểu trả về đứng trước tên

Python:

```python
def is_positive(number):
    return number > 0
```

C++:

```cpp
bool is_positive(int number) {
    return number > 0;
}
```

Đọc từ trái sang phải: hàm trả về bool, tên là is_positive, nhận một int tên number. `void` ở vị trí kiểu trả về nghĩa là hàm không trả về giá trị.

### 4. Truyền vào bản sao hay sửa trực tiếp biến bên ngoài?

Đây là khác biệt quan trọng; đừng cố quy tất cả về một quy tắc “Python truyền reference”. Trong Python, tham số được gắn với object được truyền vào: sửa object mutable và gán lại tên tham số là hai việc khác nhau.

Python:

```python
a = [1, 2]
b = a
b.append(3)
# a cũng thành [1, 2, 3]: a và b cùng trỏ đến một list.
```

C++ với vector:

```cpp
std::vector<int> a{1, 2};
std::vector<int> b = a;  // Tạo một vector riêng, sao chép các phần tử.
b.push_back(3);
// a vẫn là {1, 2}.
```

Nếu muốn thêm một tên cho chính vector a, dùng reference:

```cpp
std::vector<int>& b = a;
b.push_back(3);
// a thành {1, 2, 3}.
```

Ở dòng khai báo, `&` nói rằng b là **tên khác của chính a**, không phải vector mới. Reference đã gắn với một object thì không đổi sang gắn với object khác.

Trong tham số hàm:

```cpp
void change_copy(int x) {
    x = 99;
}

void change_original(int& x) {
    x = 99;
}

int value = 5;
change_copy(value);      // value vẫn là 5.
change_original(value);  // value thành 99.
```

| Tham số | Cách hiểu |
| --- | --- |
| `int x` | Hàm có một bản sao của số được truyền vào |
| `int& x` | Hàm truy cập trực tiếp số bên ngoài qua tên x |
| `std::vector<int> values` | Hàm nhận vector theo giá trị; truyền một vector có sẵn như biến a thường tạo bản sao |
| `std::vector<int>& values` | Hàm có thể sửa vector bên ngoài |
| `const std::vector<int>& values` | Hàm dùng vector có sẵn, không tạo bản sao chỉ để nhận tham số, và không được sửa qua values |

Tách `const std::vector<int>& values` thành ba mảnh:

1. `std::vector<int>`: một dãy int.
2. `&`: dùng trực tiếp object được truyền vào.
3. `const`: chỉ đọc qua tên này.

const ở đây không làm object bên ngoài bất biến vĩnh viễn. Người gọi vẫn có thể sửa một vector không const sau khi hàm kết thúc.

### 5. optional: gần với “int hoặc None”

Giả sử một hàm tìm một số thỏa điều kiện. Có lúc nó không tìm thấy gì. Trong Python, bạn có thể trả về None. Trong C++, một hàm trả về int không thể dùng None như vậy.

```cpp
std::optional<int> answer;   // Chưa có giá trị.
answer = 12;                 // Bây giờ có giá trị 12.
answer = std::nullopt;        // Trở về trạng thái không có giá trị.
```

`optional<int>` có **hai trạng thái**, không phải một số có giá trị mặc định đặc biệt.

| C++ | Cách hiểu tương ứng trong Python |
| --- | --- |
| `std::optional<int> answer;` | `answer = None` |
| `answer = 0;` | `answer = 0` — có giá trị, dù giá trị đó là 0 |
| `answer = std::nullopt;` | `answer = None` |
| `if (answer)` | Gần với `if answer is not None`, không phải `if answer` |
| `*answer` | Lấy int nằm bên trong, sau khi đã biết nó tồn tại |

```cpp
std::optional<int> answer = 0;
if (answer) {
    std::cout << *answer << '\n';  // In ra 0; nhánh này vẫn chạy.
}
```

**Không dùng số 0 để biểu diễn “chưa có” nếu 0 là dữ liệu hợp lệ.** Số âm cũng có thể là dữ liệu hợp lệ. Với bài 01, đó là lý do starter dùng optional.

Chỉ dùng `*answer` khi answer đang có giá trị. Ở đây `*` lấy giá trị bên trong optional; đến Stage 4 bạn sẽ thấy cùng ký hiệu được dùng với pointer.

### 6. struct: đặt tên cho từng phần của kết quả

Python có thể dùng tuple, dict hoặc dataclass để chứa dữ liệu liên quan. Một struct đơn giản trong C++ có các trường được đặt tên:

```cpp
struct Point {
    int x;
    int y;
};

Point p{2, 5};
std::cout << p.x << '\n';  // 2
```

Point là kiểu mới, p là một object của kiểu đó, còn x và y là các trường. Chưa cần inheritance hay constructor phức tạp để làm bài 02 và 04.

### Trước khi làm bài 01

Bạn chỉ cần trả lời được:

- vector chứa gì và duyệt nó thế nào?
- `const ...&` trong tham số có nghĩa gì?
- “chưa có giá trị” khác với số 0 như thế nào?
- `if (answer)` và `*answer` làm hai việc gì khác nhau?

Không cần học pointer, template nâng cao hay RAII trước bài 01. Khi gặp từ **contract**, hiểu là quy định đầu vào/đầu ra của bài. **Invariant** là điều bạn muốn luôn đúng sau mỗi bước, ví dụ “biến count là số phần tử đã thỏa điều kiện trong phần vừa duyệt”.

## Stage 2 — Chuỗi và vector (05–08)

### string sở hữu dữ liệu, string_view chỉ nhìn dữ liệu có sẵn

```cpp
std::string text = "hello";
std::string_view view = text;
```

text giữ các ký tự của nó. view chỉ là một cách nhìn vào các ký tự đó; nó không tạo một chuỗi độc lập.

Đọc **borrow/mượn** là “dùng dữ liệu có sẵn, không chịu trách nhiệm giữ dữ liệu đó tồn tại”. Đọc **own/sở hữu** là “object này quản lý dữ liệu và việc giải phóng dữ liệu đó”. Đây không phải từ khóa C++.

Nếu text bị hủy hoặc bộ nhớ chứa ký tự của nó bị thay thế, view có thể không còn hợp lệ. Khi muốn trả về một chuỗi độc lập, dùng string. Không cần tự dùng string_view trong mọi bài chỉ để tránh copy.

### size và capacity là hai con số khác nhau

```cpp
std::vector<int> values;
values.reserve(10);
// values.size() vẫn là 0: chưa có phần tử nào.
values.push_back(7);
// Bây giờ size là 1; values[0] là 7.
```

reserve chuẩn bị chỗ chứa; nó không thêm phần tử. `values.at(i)` kiểm tra chỉ số và ném exception khi ngoài phạm vi. `values[i]` đòi hỏi bạn tự bảo đảm chỉ số hợp lệ; truy cập ngoài phạm vi không được bảo đảm sẽ báo lỗi dễ đọc.

### iterator: một vị trí để đi qua container

Python thường che phần này trong for. C++ cho phép truyền vị trí bắt đầu/kết thúc vào thuật toán:

```cpp
std::reverse(values.begin(), values.end());
```

begin là vị trí đầu; end là vị trí **ngay sau phần tử cuối**. Thuật toán xử lý từ begin đến trước end. Đây là khoảng `[begin, end)`. Không đọc `*values.end()`.

Khi push_back khiến vector cần vùng nhớ mới, iterator/reference/pointer vào vùng nhớ cũ không còn dùng được. Lúc đầu, cách đơn giản là đừng giữ chúng qua một thao tác có thể thêm phần tử.

**Tự kiểm tra:** reserve có thêm phần tử không? end có phải phần tử cuối không? Kết quả string có còn dùng được sau khi input bị hủy không?

## Stage 3 — Dùng container để giải bài (09–12)

### unordered_map gần với dict

Python:

```python
positions = {"cat": 2}
if "cat" in positions:
    index = positions["cat"]
```

C++:

```cpp
std::unordered_map<std::string, int> positions{{"cat", 2}};
auto it = positions.find("cat");
if (it != positions.end()) {
    int index = it->second;
    (void)index;
}
```

- find trả về vị trí tìm thấy, hoặc end nếu không có.
- `it->first` là key; `it->second` là value.
- Trong C++, `positions["missing"]` có thể **thêm** key mới với value int bằng 0. Python dict thông thường báo KeyError khi đọc key không tồn tại. Vì vậy dùng find khi chỉ muốn kiểm tra/tìm.

### Đọc độ phức tạp bằng lượng công việc

| Ký hiệu | Cách hình dung |
| --- | --- |
| O(n) | Đi qua n phần tử với lượng việc cố định ở mỗi bước |
| O(n²) | Chẳng hạn thử mọi cặp phần tử |
| O(log n) | Chẳng hạn mỗi bước loại bỏ khoảng một nửa vùng tìm kiếm |

unordered_map thường có lookup trung bình O(1), nhưng đó không phải bảo đảm cho mọi trường hợp. Bài 09 giúp bạn so sánh việc thử mọi cặp với việc nhớ các giá trị đã đi qua.

Binary search cần dữ liệu có thứ tự. Sliding window theo dõi một đoạn liên tiếp đang xét, thay vì tính lại từ đầu cho mọi đoạn. Hãy đọc contract và trace ví dụ trước khi chọn pattern.

Một chi tiết cho bài 10/12: char có thể mang giá trị âm trên một số hệ thống. Khi dùng một byte làm chỉ số bảng 256 phần tử, dùng `static_cast<unsigned char>(c)` để có chỉ số 0–255. Các bài xử lý byte, chưa xử lý đầy đủ ký tự Unicode.

**Tự kiểm tra:** find không thấy thì trả gì? Vì sao [] có thể làm thay đổi map? Mỗi vòng của binary search thu hẹp vùng tìm ở đâu?

## Stage 4 — Pointer, lifetime, ownership và đệ quy (13–16)

### Pointer chứa địa chỉ; reference là tên khác của object

```cpp
int value = 10;
int* pointer = &value;
*pointer = 25;
// value bây giờ là 25.
```

Đọc từng dòng:

1. Tạo số nguyên value bằng 10.
2. `int*` là kiểu pointer đến int; `&value` lấy địa chỉ của value.
3. `*pointer` truy cập object tại địa chỉ đó; gán 25 làm value đổi thành 25.

Ký hiệu & có hai vai trò tùy vị trí: trong `int& alias = value`, nó khai báo reference; trong biểu thức `&value`, nó lấy địa chỉ. Tương tự, `int*` là tên kiểu pointer, còn `*pointer` là thao tác truy cập qua pointer.

Pointer có thể bằng nullptr để nói rằng nó không trỏ đến object nào. Không dùng `*pointer` khi nó là nullptr. Pointer không tự mang chiều dài mảng; vì vậy bài 13 nhận cả data và n.

`const int*` cho phép đọc int nhưng không sửa nó **qua pointer này**. Bài 16 có hai overload: cùng tên hàm, nhưng một bản nhận int* để có thể sửa kết quả, một bản nhận const int* để chỉ đọc.

### Lifetime: object còn tồn tại đến khi nào?

```cpp
int* bad_example() {
    int local = 5;
    return &local;  // Sai: local bị hủy khi hàm kết thúc.
}
```

Đây là ví dụ sai có chủ đích: đừng chạy hoặc dùng nó làm mẫu. Địa chỉ được trả về không giữ local tồn tại. **Dangling pointer/reference/view** là một cách truy cập đang nhắc đến object/vùng nhớ không còn hợp lệ. Một địa chỉ không null vẫn có thể dangling.

### unique_ptr: giao trách nhiệm giữ và giải phóng object cho một owner

```cpp
auto owner = std::make_unique<int>(7);
int* observer = owner.get();
auto new_owner = std::move(owner);
```

- make_unique tạo object và trả về unique_ptr quản lý nó.
- get cho một pointer để quan sát; observer không chịu trách nhiệm giải phóng object.
- Dòng cuối chuyển quyền quản lý sang new_owner. Với unique_ptr, owner cũ trở thành rỗng.
- Object int vẫn ở chỗ cũ, nên observer còn hợp lệ **chừng nào object đó vẫn tồn tại**.
- Khi owner cuối này bị hủy hoặc reset, object được giải phóng; không dùng observer nữa.

unique_ptr không cho copy để tránh hai owner cùng nhận trách nhiệm độc quyền. std::move cho phép dùng thao tác move; nó không có nghĩa là mọi kiểu đều bị xóa/rỗng sau move. Quy tắc phụ thuộc kiểu; bài 20 sẽ yêu cầu bạn tự định nghĩa trạng thái của class sau move.

### Đệ quy và backtracking

Đệ quy là hàm gọi lại chính nó, với một điều kiện dừng. Backtracking thường có ba bước: thêm lựa chọn → gọi tiếp → bỏ lựa chọn để thử nhánh khác.

Python `result.append(current)` giữ tham chiếu đến cùng list; thường cần `current.copy()`. C++ `result.push_back(current)` với vector<vector<int>> sẽ copy vector current thành một phần tử độc lập. Đây là khác biệt hữu ích cho bài 15.

**Tự kiểm tra:** ai sở hữu node trong bài 14? Pointer trả về ở bài 16 cần input tồn tại đến khi nào? Vì sao phải undo lựa chọn sau một nhánh đệ quy?

## Stage 5 — Class, copy/move và đa hình (17–20)

### Một class đơn giản giống Python ở đâu?

Python:

```python
class Counter:
    def __init__(self, start):
        self.value = start

    def increment(self):
        self.value += 1
```

C++:

```cpp
class Counter {
    int value_;
public:
    explicit Counter(int start) : value_(start) {}
    void increment() { ++value_; }
    int value() const { return value_; }
};
```

- Counter(int start) là constructor, gần với vai trò khởi tạo của __init__.
- `: value_(start)` khởi tạo member value_ bằng start.
- Dữ liệu trước public mặc định là private: code bên ngoài không truy cập trực tiếp.
- Trong member function, bạn dùng value_ trực tiếp; không cần viết self.value.
- const ở cuối value() cho biết method này không sửa trạng thái thông thường của object.
- explicit ngăn một số chuyển đổi ngầm không mong muốn; chưa cần thành thạo quy tắc đó để đọc ví dụ.

**Class invariant** là điều class phải duy trì, ví dụ “số hàng trong kho không âm”. Constructor thiết lập điều đó; các method phải giữ nó đúng sau mỗi thao tác hợp lệ.

### Copy khác Python assignment

Với một class chứa vector/map/string thông thường, `auto b = a` copy các member đó, nên b có dữ liệu riêng. Trong Python, `b = a` chỉ gắn thêm tên vào cùng instance.

Có class cố ý không cho copy, ví dụ class sở hữu độc quyền tài nguyên. Bài 20 dạy bạn cấm copy và cho move. Hãy phân biệt:

| C++ | Đang làm gì? |
| --- | --- |
| `Thing b = a;` | Tạo b từ a: copy construction |
| `b = a;` khi b đã có | Thay giá trị b: copy assignment |
| `Thing b = std::move(a);` | Tạo b qua move nếu có move constructor phù hợp |
| `b = std::move(a);` | Move assignment nếu có overload phù hợp |

**Rule of Zero** chỉ là lời khuyên: khi container/smart pointer đã lo tài nguyên, đừng tự viết destructor/copy/move nếu không cần. Bài 20 là trường hợp có yêu cầu riêng về moved-from state nên phải xử lý thêm.

### virtual và override

Python thường chọn method từ object lúc chạy. C++ cần khai báo virtual khi bạn muốn gọi qua pointer/reference đến base mà vẫn chạy method của derived.

Bài 19 cung cấp interface Shape. area là virtual; Rectangle và Square viết override. clone tạo một object mới có đúng kiểu thực tế. Đừng copy một derived object vào một base object theo giá trị: phần dữ liệu/đặc tính derived có thể bị mất, gọi là **slicing**. Khi hủy derived qua pointer đến base, base cần virtual destructor; interface đã cung cấp sẵn.

**Tự kiểm tra:** điều gì luôn đúng về Fraction? Inventory copy có độc lập không? Bài 20 phải giữ size của object sau move thế nào?

## Stage 6 — STL, lambda, template và iterator (21–24)

### Lambda là một hàm nhỏ viết ngay tại nơi sử dụng

Python:

```python
twice = lambda x: x * 2
```

C++:

```cpp
auto twice = [](int x) { return x * 2; };
int result = twice(5);  // 10
```

`[]` là phần capture: ví dụ `[offset]` giữ bản copy của biến ngoài, `[&offset]` dùng chính biến ngoài. Capture bằng reference không kéo dài lifetime của biến đó.

### Template giúp một cách xử lý dùng được với nhiều kiểu

```cpp
template<class T>
T identity(T value) {
    return value;
}
```

Gọi với int thì T được suy ra là int; gọi với string thì T là string. Compiler tạo phiên bản phù hợp. Kiểu vẫn được kiểm tra khi compile, không phải chọn động như Python.

Bài 21 đổi kiểu phần tử đầu ra theo callable. Đến bài đó mới cần đọc các mảnh sau:

| Mảnh cú pháp | Cách hiểu để làm bài |
| --- | --- |
| `decltype(expression)` | Hỏi compiler kiểu của expression, không chạy expression |
| `std::declval<const T&>()` | Dùng để mô tả một đầu vào const T& trong phép hỏi kiểu; không gọi khi chương trình chạy |
| `std::decay_t<...>` | Bỏ reference/const cần thiết để có một kiểu giá trị có thể lưu trong vector |
| `typename std::iterator_traits<It>::value_type` | Kiểu phần tử mà iterator It truy cập; typename báo đây là tên kiểu |

Không cần thuộc các tên dài trước bài 01. Khi đến đây, tách từng mảnh thay vì đọc cả dòng như một khối.

### STL algorithm và comparator

```cpp
std::sort(values.begin(), values.end(), [](int a, int b) {
    return a > b;
});
```

Comparator trả true nếu a cần đứng trước b. Dùng > để xếp giảm dần; không dùng >=, vì hai phần tử bằng nhau không được đồng thời được xem là đứng trước nhau. stable_sort giữ thứ tự đầu vào của các phần tử bằng nhau theo comparator.

Bài 24 dùng iterator để làm việc với cả vector và list. Không giả sử mọi iterator đều hỗ trợ trừ hai vị trí hay dùng chỉ số; list iterator chỉ cần đi tiếp bằng ++ cho bài này.

**Tự kiểm tra:** template khác kiểu động của Python ở đâu? Vì sao dùng >= trong comparator sai? Vì sao test bằng list lại giúp phát hiện lỗi thiết kế?

## Stage 7 — Parse, stream, exception và RAII (25–28)

### Stream: đọc cùng một thuật toán từ chuỗi hoặc file

```cpp
std::istringstream input("12 34");
int number;
while (input >> number) {
    std::cout << number << '\n';
}
```

`input >> number` thử đọc và chuyển dữ liệu vào number; điều kiện vòng lặp chỉ đúng khi đọc thành công. istringstream đọc từ chuỗi; ifstream đọc từ file. Hàm nhận istream& có thể dùng với cả hai.

```cpp
std::ifstream input("numbers.txt");
if (!input) {
    throw std::runtime_error("Cannot open numbers.txt");
}
```

Include <fstream> khi dùng file. Không dùng `while (!input.eof())` để quyết định có một lần đọc thành công nữa hay không. Hãy thử đọc rồi kiểm tra kết quả.

Vòng đọc int đơn giản chưa đủ cho bài 25: chuỗi "3x" có thể bị đọc một phần thành 3. Bài yêu cầu parse toàn token, nên dùng from_chars và kiểm tra cả mã lỗi lẫn vị trí đọc dừng.

### optional hay exception?

- optional: API cho phép “không có kết quả” như một kết quả thông thường.
- exception: API báo thao tác không thực hiện được theo cách đó.

Python dùng raise; C++ dùng throw. Python dùng try/except; C++ dùng try/catch. Trong bài tập, làm đúng cách báo lỗi được ghi trong contract, không tự đổi giữa hai cách.

variant<int,bool,string> chứa một trong ba kiểu. holds_alternative kiểm tra kiểu hiện tại; get lấy giá trị đúng kiểu. optional<variant<...>> thêm trường hợp parse thất bại, tách biệt với int 0, bool false hay string rỗng.

### RAII: object tự dọn khi ra khỏi scope

Python thường dùng `with open(...) as file:` để đóng file kể cả khi có exception. C++ dùng object có destructor thực hiện dọn dẹp khi object kết thúc lifetime.

```cpp
{
    std::ifstream file("notes.txt");
    // Dùng file ở đây.
} // file bị hủy; tài nguyên file được đóng tự động.
```

Destructor viết dưới dạng ~ClassName(). Nó cũng được gọi khi exception làm chương trình thoát khỏi scope đó. RAII là tên cho cách gắn trách nhiệm dọn tài nguyên/khôi phục trạng thái với lifetime của object.

Bài 28 áp dụng ý tưởng này để lưu và khôi phục định dạng stream. Guard không sở hữu stream: stream phải còn tồn tại khi destructor của guard chạy. Destructor dọn dẹp không nên ném exception.

**Tự kiểm tra:** đọc từ file và từ chuỗi có thể dùng chung hàm nào? Parse sai khác EOF ở đâu? Vì sao guard vẫn khôi phục trạng thái khi có exception?

## Khi một dòng vẫn khó đọc

Đừng cố nhớ mọi thuật ngữ cùng lúc. Với dòng đang gặp, xác định: kiểu dữ liệu là gì, tên nào là biến, hàm nào được gọi, dữ liệu bị copy hay dùng trực tiếp, và object nào cần còn tồn tại. Có thể hỏi giải thích đúng dòng đó trước khi học phần tiếp theo.
