// source: https://www.codewars.com/kata/545cedaa9943f7fe7b000048/train/pascal
(*
   A pangram is a sentence that contains every single letter of the alphabet at least once. 
   For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, 
   because it uses the letters A-Z at least once (case is irrelevant).
   Given a string, detect whether or not it is a pangram. Return True if it is, False if not. 
   Ignore numbers and punctuation
*)

program DetectPangram;



function IsPangram (s: string): boolean;
var
   alphabet: array[char] of Integer;
   c: char;

begin
   // init array with 0s:
   for c := 'a' to 'z' do
      begin
         alphabet[c] := 0;
      end;
   
   // count all letters:
   for c in s do
      begin
         inc(alphabet[lowercase(c)]);
      end;

   // see if any is 0:
   for c := 'a' to 'z' do
      begin
         if(alphabet[c] = 0) then
            exit(false)
      end;

   exit(true);
end;



// test code here
const
   pangram = 'The quick brown fox jumps over the lazy dog';
   notPangram = 'Hello World';
begin
   writeln('IsPangram (false): ', IsPangram(notPangram));
   writeln('IsPangram (true): ', IsPangram(pangram));
end. 


