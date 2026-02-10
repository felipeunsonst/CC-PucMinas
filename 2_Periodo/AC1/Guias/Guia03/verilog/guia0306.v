//Felipe Costa Unsonst
//854155

module Complemento1 (
    input [7:0] in,
    output [7:0] out
);
    assign out = ~in;
endmodule

module Complemento2 (
    input [7:0] in,
    output [7:0] out
);
    assign out = ~in + 1;
endmodule

module Complemento_Teste;
    reg [7:0] in;
    wire [7:0] out1, out2;

    Complemento1 comp1 (
        .in(in),
        .out(out1)
    );

    Complemento2 comp2 (
        .in(in),
        .out(out2)
    );

    initial begin
        $display("Complemento de 1 e Complemento de 2 - Teste");

        in = 8'b10101010;
        #1 $display("in = %8b -> Complemento de 1 = %8b, Complemento de 2 = %8b", in, out1, out2);

        in = 8'b11001100;
        #1 $display("in = %8b -> Complemento de 1 = %8b, Complemento de 2 = %8b", in, out1, out2);

        in = 8'b00000001;
        #1 $display("in = %8b -> Complemento de 1 = %8b, Complemento de 2 = %8b", in, out1, out2);
    end
endmodule
