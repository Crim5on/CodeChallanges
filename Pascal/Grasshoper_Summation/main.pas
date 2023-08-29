// source: https://www.codewars.com/kata/55d24f55d7dd296eb9000030/train/pascal
(*
   Write a program that finds the summation of every number from 1 to num. The number will always be a positive integer greater than 0
*)

program GrashopperSummation;



function Summation(const N: Integer): Integer;
var 
   i: Integer;
   sum: Integer;
begin
   i := 0;
   sum := 0;

   for i := 0 to N do
      begin
         sum := sum + i;
      end;

   exit(sum);
end;



// testcode here
var
   result: Integer;
begin
   result := Summation(5);
   writeln('Summation: ', result);
end. 
