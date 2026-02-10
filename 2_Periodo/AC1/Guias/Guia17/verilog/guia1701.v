//854155 FELIPE COSTA UNSONST
module maq_d(input wire A, B, output wire Da, Db);
    assign Da = B;
    assign Db = (~A) | B;
endmodule

`timescale 1ns/1ps
module maq_d_tb;
    reg A, B;
    wire Da, Db;

    maq_d uut (.A(A), .B(B), .Da(Da), .Db(Db));

    initial begin
        $display("A B | Da Db");
        $monitor("%b %b | %b  %b", A, B, Da, Db);

        A=0; B=0; #10;
        A=0; B=1; #10;
        A=1; B=0; #10;
        A=1; B=1; #10;

        $finish;
    end
endmodule

    
