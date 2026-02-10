// FELIPE COSTA UNSONST
// 854155

module halfAdder ( output carry, output sum, input a, input b ); 
    xor XOR0 ( sum, a, b ); 
    and AND0 ( carry, a, b ); 
endmodule  

module fullAdder ( output carry, output sum, input a, input b, input carryIn ); 
    wire w1, w2, w3;
    halfAdder HA0 ( w1, w2, a, b );
    halfAdder HA1 ( w3, sum, w2, carryIn );
    or OR1 ( carry, w1, w3 );
endmodule 

module AU (
    input [5:0] A,       
    input [5:0] B,        
    input carryIn,        
    input chave,         
    output reg [5:0] resultado, 
    output reg igual,     
    output reg diferente  
); 
    wire [5:0] B_invertido;
    wire [5:0] soma;        
    wire [4:0] carry;      

  
    assign B_invertido = (carryIn) ? ~B : B;

    fullAdder FA0 ( carry[0], soma[0], A[0], B_invertido[0], carryIn ); 
    fullAdder FA1 ( carry[1], soma[1], A[1], B_invertido[1], carry[0] ); 
    fullAdder FA2 ( carry[2], soma[2], A[2], B_invertido[2], carry[1] ); 
    fullAdder FA3 ( carry[3], soma[3], A[3], B_invertido[3], carry[2] ); 
    fullAdder FA4 ( carry[4], soma[4], A[4], B_invertido[4], carry[3] ); 
    assign soma[5] = carry[4];

    always @(*) begin
        igual = (A == B);
        diferente = (A != B);
        
        if (chave) begin
            resultado = soma; 
        end else begin
            resultado = igual ? 6'b111111 : 6'b000000;
        end
    end

endmodule 

module Guia_0806; 
    reg [5:0] A; 
    reg [5:0] B; 
    reg carryIn; 
    reg chave; 
    wire [5:0] resultado; 
    wire igual; 
    wire diferente; 

    AU minhaAU ( A, B, carryIn, chave, resultado, igual, diferente );

    initial begin 
        A = 6'b000000; 
        B = 6'b000000; 
        carryIn = 0; 
        chave = 1; 
    end 
 
    initial begin 
        $display("Testando a Unidade Aritmética"); 
        $display("  A   +   B   =  Resultado  | Igual | Diferente"); 
        for (integer i = 0; i < 32; i++) begin
            for (integer j = 0; j < 32; j++) begin
                A = i; 
                B = j; 
                carryIn = 0;
                chave = 1; 
                #10;
                $display("%b + %b = %b | %b | %b", A, B, resultado, igual, diferente);
                
                carryIn = 1; 
                #10;
                $display("%b - %b = %b | %b | %b", A, B, resultado, igual, diferente);
            end 
        end 
        $finish; 
    end 
endmodule 
