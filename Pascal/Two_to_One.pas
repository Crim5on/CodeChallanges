// source: https://www.codewars.com/kata/5656b6906de340bd1b0000ac/train/pascal
(*
    Take 2 strings s1 and s2 including only letters from a to z. 
    Return a new sorted string, the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.
*)

program Two_to_One;


function SortString(s: String): String;
var
	i, j:	Integer;	// loop counter
	swap: Char;
	stringLength: Integer;
begin
	stringLength := length(s);

	for i:=1 to (stringLength-1) do 
	begin
		for j:=1 to (stringLength-1) do
		begin
			if (s[j] > s[j+1]) then
			begin
				swap := s[j];
				s[j] := s[j+1];
				s[j+1] := swap;
			end;
		end;
	end;
	SortString := s;
end;


function isNotInString(c: Char; s: String): Boolean;
var
	cs: Char;
begin
	for cs in s do
	begin
		if (cs = c) then
			Exit(False);
	end;
	isNotInString := True;
end;


function checkAppend(s, sx: String): String;
var
	c: Char;
begin
	for c in sx do
	begin
		if (isNotInString(c, s)) then
			s := concat(s, c);
	end;
	checkAppend := s;
end;


function Longest(s1, s2: String): String;
var
	resultString: String;
begin
	resultString := '';
	resultString := checkAppend(resultString, s1);
	resultString := checkAppend(resultString, s2);
	resultString := SortString(resultString);
  	Longest := resultString;
end;



// main
var
    result: String;
begin
    result := Longest('hello', 'world');
    writeln('Result: ', result);
end.
