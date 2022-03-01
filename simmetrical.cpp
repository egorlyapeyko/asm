#include <iostream>
int main() {
	int n;
    int res;
	std::cout << "Please, enter the natural number: \n";
	do
	{
		std::cin >> n;
	}
    while (n < 0);
	std::cout << "Your number is " << n;
    _asm {
        mov esi, 1
        mov eax, n;
        xor ecx, ecx
            mov ebx, 10

            form_digits_loop:
       test eax, eax
            jz continue
            xor edx, edx
            div ebx
            push edx
            inc ecx
            jmp form_digits_loop
            continue:
            mov edi, esp
            lea edx, [edi + ecx * 4 - 4]
            mov ebx, ecx
            shr ecx, 1
            cmp_loop :
            jecxz finish
            mov eax, ss : [edi]
            cmp eax, ss : [edx]
            jne not_equal
            sub edx, 4
            add edi, 4
            dec ecx
            jmp cmp_loop
            not_equal :
        xor esi, esi
            finish :
        lea esp, [esp + ebx * 4]
            mov res, esi
    }
    if (res)
        std::cout << ". Symmetric\n";
    else
        std::cout << ". It is not symmetric\n";
    return 0;

}