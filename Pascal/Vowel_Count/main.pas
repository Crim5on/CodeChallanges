// 	source: https://www.codewars.com/kata/54ff3102c1bad923760001f3/train/pascal
(*
   	Return the number (count) of vowels in the given string.
	We will consider a, e, i, o, u as vowels for this Kata (but not y).
	The input string will only consist of lower case letters and/or spaces
*)

program VowelCount;
uses crt, sysutils;



Function IsVowel(c: char): boolean;
var
	lower_c: char;
begin
	lower_c := lowercase(c);

	if ((lower_c = 'a') or (lower_c = 'e') or (lower_c = 'i') or (lower_c = 'o') or (lower_c = 'u')) then
		begin
			exit(true);
		end
	else
		begin
			exit(false);
		end;
end;



Function GetCount(s: string): Integer;
var
	cnt: Integer;
	i: Integer;
	stringLength: Integer;

begin
	cnt := 0;
	stringLength := length(s);

	for i := 0 to stringLength do
		begin
			if (IsVowel(s[i])) then
				begin
					Inc(cnt);
				end;
		end;
	exit(cnt);
end;



var 
	result: Integer;
	test1: boolean;
const
	testinput = 'abracadabra';
begin
	// test IsVowel function:
	test1 := IsVowel('y');
	writeln('IsVowel: ', test1);

	// test GetCount function:
	result := GetCount(testinput);
	writeln('Number of Vowels in ', testinput, ' : ', result);
end. 
