// source: https://www.codewars.com/kata/55f9b48403f6b87a7c0000bd/train/pascal
(*
   Your classmates asked you to copy some paperwork for them. You know that there are 'n' classmates and the paperwork has 'm' pages.
   Your task is to calculate how many blank pages do you need. If n < 0 or m < 0 return 0
*)

program SchoolPaperwork;


function Paperwork (n: Integer; m: Integer): Integer;
begin
   if ((n < 0) or (m < 0)) then
      exit(0)
   else
      exit(m*n)
end;



(* this is a comment *)
var 
   retVal: Integer;
begin
   retVal := Paperwork(5, 5);
   writeln('retVal: ', retVal);
end. 
