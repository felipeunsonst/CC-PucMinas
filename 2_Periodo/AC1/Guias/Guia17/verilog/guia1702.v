//FELIPE COSTA UNSONST - 854155
module maq_jk_sr(input wire A, B, output wire Ja, Ka, Jb, Kb);
    assign Ja = B;
    assign Ka = ~A & B;
    assign Jb = A;
    assign Kb = A;
endmodule

`timescale 1ns/1ps
module maq_jk_sr_tb;
    reg A, B;
    wire Ja, Ka, Jb, Kb;

    maq_jk_sr uut (.A(A), .B(B), .Ja(Ja), .Ka(Ka), .Jb(Jb), .Kb(Kb));

    initial begin
        $display("A B | Ja Ka Jb Kb");
        $monitor("%b %b | %b  %b  %b  %b", A, B, Ja, Ka, Jb, Kb);

        A=0; B=0; #10;
        A=0; B=1; #10;
        A=1; B=0; #10;
        A=1; B=1; #10;

        $finish;
    end
endmodule

    
