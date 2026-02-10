// FELIPE COSTA UNSONST
// 854155

module Adicao;
  reg [7:0] a, b;
  wire [7:0] sum;

  initial begin
    $display("Adicao - 101.01(2) + 10.011(2)");
    a = 8'b1010100;
    b = 8'b00100011;
    assign sum = a + b;
    $display("Result = %b", sum);
  end
endmodule

module Subtracao;
  reg [7:0] a, b;
  wire [7:0] diff;

  initial begin
    $display("Subtracao - 1000.001(2) - 10.01(2)");
    a = 8'b10000001; 
    b = 8'b00010010; 
    assign diff = a - b;
    $display("Result = %b", diff);
  end
endmodule

module Multiplicacao;
  reg [7:0] a, b;
  wire [15:0] product;

  initial begin
    $display("Multiplicacao - 101.110(2) * 10.001(2)");
    a = 8'b1011100; 
    b = 8'b00100010; 
    assign product = a * b;
    $display("Result = %b", product);
  end
endmodule

module Divisao;
  reg [15:0] a, b;
  wire [15:0] quotient;
  wire [15:0] remainder;

  initial begin
    $display("Divisao - 10110.01(2) / 11.011(2)");
    a = 16'b1011001000; 
    b = 16'b00011011; 
    assign quotient = a / b;
    assign remainder = a % b;
    $display("Quotient = %b", quotient);
    $display("Remainder = %b", remainder);
  end
endmodule

module Resto;
  reg [15:0] a, b;
  wire [15:0] remainder;

  initial begin
    $display("Resto - 1101101(2) % 1011(2)");
    a = 16'b1101101; 
    b = 16'b1011;
    assign remainder = a % b;
    $display("Result = %b", remainder);
  end
endmodule
