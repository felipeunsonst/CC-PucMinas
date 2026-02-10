//FELIPE COSTA UNSONST
// 854155

module comparator ( output igual, output diferente, input [5:0] A, input [5:0] B ); 
    assign igual = (A == B);
    assign diferente = (A != B);
endmodule  

module LU (
    input [5:0] A,        
    input [5:0] B,
    input chave,         
    output reg resultado   
); 
    wire igual;          
    wire diferente;       

    comparator comp ( igual, diferente, A, B );

    always @(*) begin
        if (chave) begin
            resultado = diferente; 
        end else begin
            resultado = igual;
        end
    end

endmodule 

module Guia_0807; 
    reg [5:0] A; 
    reg [5:0] B; 
    reg chave; 
    wire resultado; 

    // Instância da LU
    LU minhaLU ( A, B, chave, resultado );

    initial begin 
        A = 6'b000000; 
        B = 6'b000000; 
        chave = 0; 
    end 

    initial begin 
        $display("Guia_0807 - Vinicius Miranda de Araujo - 812839"); 
        $display("Testando a Unidade Lógica"); 
        $display(" A    B   |  Resultado | Chave"); 
        for (integer i = 0; i < 32; i++) begin
            for (integer j = 0; j < 32; j++) begin
                A = i; 
                B = j; 
                
                chave = 0; 
                #10;
                $display("%b %b | %b | %b", A, B, resultado, chave);
                
                chave = 1; 
                #10;
                $display("%b %b | %b | %b", A, B, resultado, chave);
            end 
        end 
        $finish; 
    end 
endmodule 

    
