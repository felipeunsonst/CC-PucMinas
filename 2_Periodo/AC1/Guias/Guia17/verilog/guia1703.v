//FELIPE COSTA UNSONST - 854155
module maq_jk_toggle(input wire A, B, output wire Ta, Tb);
    assign Ta = ~A & B;
    assign Tb = A | B;
endmodule

`timescale 1ns/1ps
module maq_jk_toggle_tb;
    reg A, B;
    wire Ta, Tb;

    maq_jk_toggle uut (.A(A), .B(B), .Ta(Ta), .Tb(Tb));

    initial begin
        $display("A B | Ta Tb");
        $monitor("%b %b | %b  %b", A, B, Ta, Tb);

        A=0; B=0; #10;
        A=0; B=1; #10;
        A=1; B=0; #10;
        A=1; B=1; #10;

        $finish;
    end
endmodule

    
