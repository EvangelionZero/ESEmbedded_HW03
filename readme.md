HW03
===
#1.實驗題目

撰寫c語言檔案觀察函式在組合語言下如何傳遞(pass)值與回傳(return)值

#2.實驗步驟

*1.先將資料夾 gnu-mcu-eclipse-qemu 完整複製到 ESEmbedded_HW03 資料夾中
*2.編輯.c檔,分別建立數個void,int等性質的函式
*3.編輯.s檔,將自己要用到的.c檔的函式名稱寫在其中
在此僅放較重要的.c檔,.s檔中所用到的函式為reset_handler_1
```
void reset_handler_1(void)
{
	int a=1;
	a=reset_handler_2(a);
}


int reset_handler_2(int a)
{
	a=a+1;
	a=reset_handler_3(a);
	return a;	
}

int reset_handler_3(int a)
{
	int b=6;
	b=a*b;
	return b;
}
```
* 4.將 main.s 編譯並以 qemu 模擬， `$ make clean `, `$ make` , `$ make qemu `開啟另一 Terminal 連線` $ arm-none-eabi-gdb `，再輸入 `target remote localhost:1234` 連接，輸入兩次的 `ctrl + x `再輸入 `2`, 開啟 暫存器以及指令，並且輸入` si `單步執行觀察。當執行到某個函式的某個`local`運算,觀察是哪個暫存器所存取,再觀察當執行到某個函式呼叫另一函式時要`pass`或`return`值,觀察是哪個暫存器所存取

# 3.結果與討論
*1.從實驗結果可以發現,`local`運算時所使用到的暫存器皆為r3(若更多則會用到r2等),而在`pass`值或`return`值時所使用到的暫存器皆為r0


- [x] **If you volunteer to give the presentation next week, check this.**

--------------------

**★★★ Please take your note here ★★★**
