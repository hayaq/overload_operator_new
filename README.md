overload_operator_new
=====================

Some test codes for overloading c++ operator 'new[]'

C++でnew[]をオーバーロードしたとき内部でmallocで確保したアドレスと
new[]からかえってくるアドレスが，new[]する対象(POD or non-POD)によって異なるので，
それをランタイム時に検証するコード．
アドレスが異なってくるのは，new[]がmallocから得られたアドレスの先頭8 or 4バイトに配列の個数を
書き込み，そのバイト分ずらしたアドレスを返しているため．

テストコードのCではnon-POD型をnew[]しているが，placement-newになるためアドレスのずれが生じない．

Example of results on g++/x86_64

```c
new[](size=1,address=0x7fff5cbf2b20)
A raw ptr = 0x7fff5cbf2b20
A new ptr = 0x7fff5cbf2b20
A offset  = 0

new[](size=9,address=0x7fff5cbf2b10)
B raw ptr = 0x7fff5cbf2b10
B new ptr = 0x7fff5cbf2b18
B offset  = 8

new[](size=1,address=0x7fff5cbf2b00)
C raw ptr = 0x7fff5cbf2b00
C new ptr = 0x7fff5cbf2b00
C offset  = 0
```
