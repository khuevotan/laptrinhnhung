volatile int trangthai = HIGH; 
// khai báo biến kiểu volatile, tránh sai số trong quá trình thực hiện ngắt.
void setup()                  
{ 
    pinMode(13, OUTPUT); // khai báo led là ngõ ra
    digitalWrite(2, HIGH);    // Treo chân ngắt 0, chân số 2 lên mức cao.
    attachInterrupt(0, daoled, CHANGE); // khai báo ngắt 0, chương trình con daoled, chế độ có sự                                                            //  thay đổi là sinh ngắt
} 
void loop()                           // đoạn chương trình chính, vòng lặp vô tận.
{
    digitalWrite(13, trangthai);           // gán trạng thái cho chân led.
 } 
void daoled()                       // chương trình con ngắt, khi có ngắt xảy ra sẽ thực hiện chương trình này.
{ 
    trangthai = !trangthai;   // đảo trang thái.
}
