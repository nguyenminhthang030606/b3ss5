1. Phân tích, Đề xuất & Lựa chọn giải pháp
Input/Output:

In: Số lượng n (0-100), mảng tuoi, bhyt, vị trí cần hủy K.

Out: Danh sách hàng chờ, doanh thu, ca ưu tiên (trước và sau khi hủy).

3 Giải pháp xử lý hủy lượt:

Dồn dịch mảng (Hard Delete): Xóa tại K, dịch mảng từ K+1 sang trái lấp chỗ, giảm n. (Giữ thứ tự, O(n)).

Đánh dấu (Soft Delete): Dùng mảng trạng thái phụ, gán = 0 khi hủy. (Giữ thứ tự, O(1) nhưng rác bộ nhớ, code phức tạp sau này).

Đổi chỗ phần tử cuối: Đem phần tử cuối cùng đè lên K, giảm n. (O(1) nhưng làm đảo lộn thứ tự).

Lựa chọn: Chọn Giải pháp 1 (Dồn dịch mảng). Lý do: Nghiệp vụ phòng khám bắt buộc tuân thủ FIFO (vào trước khám trước). Tuy tốn O(n) thời gian nhưng với n tối đa 100 thì không đáng kể, bù lại đảm bảo tuyệt đối tính toàn vẹn và thứ tự dữ liệu.
