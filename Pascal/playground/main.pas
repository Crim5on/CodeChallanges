(* source:  https://www.codewars.com/kata/..
   <desctiption>
*)


// C style comment (legal?)
program HelloWorld;
uses crt, sysutils;


Function sayHello(yourname: string): boolean;
var
   	message: string;
const
   	greeting = 'Good Morning, ';
begin
	message := greeting + yourname + '!';
	writeln(message);
   sayHello := true;    // return
end;


{ this is a single line comment }
var 
	userinput: string;
	success: boolean;
begin
	writeln('State your name:');
	readln(userinput);
	success := sayHello(userinput);
   writeln('PMG Success: ', success);
end. 
