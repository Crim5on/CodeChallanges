// source: https://www.codewars.com/kata/5506b230a11c0aeab3000c1f/train/pascal
(*
    This program tests the life of an evaporator containing a gas.
	We know the content of the evaporator (content in ml), the percentage of foam or gas lost every day (evap_per_day) 
	and the threshold (threshold) in percentage beyond which the evaporator is no longer useful. All numbers are strictly positive.
	The program reports the nth day (as an integer) on which the evaporator will be out of use.
*)

program Deodorant_Evaporator;


Function evaporator(content, evapPerDay, threshold: Double): Int64;
var 
	remainingContent: Double;
    dayOfNoReturn: Int64;
begin
	dayOfNoReturn := 0;
	remainingContent := 100;
	while (remainingContent > threshold) do 
	begin
		remainingContent := remainingContent - ((remainingContent/100) * evapPerDay);
		Inc(dayOfNoReturn);
	end;

    evaporator := dayOfNoReturn;
end;


var
    result: Int64;
begin
    result := evaporator(10, 10, 5); // -> 29
    writeln('Result: ', result);
end.
