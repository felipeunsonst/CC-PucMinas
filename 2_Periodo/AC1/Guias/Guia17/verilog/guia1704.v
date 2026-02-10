//FELIPE COSTA UNSONST - 854155
module contador_async1(input wire clk, output reg Q1=0, Q2=0, Q3=0);
    always @(posedge clk) Q1 <= ~Q1;
    always @(posedge Q1)  Q2 <= ~Q2;
    always @(posedge Q2)  Q3 <= ~Q3;
endmodule

`timescale 1ns/1ps
module contador_async1_tb;
    reg clk = 0;
    wire Q1, Q2, Q3;

    contador_async1 uut (.clk(clk), .Q1(Q1), .Q2(Q2), .Q3(Q3));

    always #5 clk = ~clk;

    initial begin
        $display("clk | Q3 Q2 Q1");
        $monitor("%b   | %b  %b  %b", clk, Q3, Q2, Q1);

        #100;
        $finish;
    end
endmodule

    
