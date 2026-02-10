//FELIPE COSTA UNSONST
//854155

// Exercício 01 - AND/NAND com seleção
module Guia_0701 (
    input A, B, sel,
    output S
);
    wire and_out, nand_out;
    and (and_out, A, B);
    nand (nand_out, A, B);
    assign S = (sel & nand_out) | (~sel & and_out);
endmodule

// Exercício 02 - OR/NOR com seleção
module Guia_0702 (
    input A, B, sel,
    output S
);
    wire or_out, nor_out;
    or (or_out, A, B);
    nor (nor_out, A, B);
    assign S = (sel & nor_out) | (~sel & or_out);
endmodule

// Exercício 03 - Seletor entre AND/NAND e OR/NOR
module Guia_0703 (
    input A, B, sel1, sel2,
    output S
);
    wire and_out, nand_out, or_out, nor_out, sel_and_nand, sel_or_nor;
    and (and_out, A, B);
    nand (nand_out, A, B);
    or (or_out, A, B);
    nor (nor_out, A, B);
    assign sel_and_nand = (sel1 & nand_out) | (~sel1 & and_out);
    assign sel_or_nor = (sel1 & nor_out) | (~sel1 & or_out);
    assign S = (sel2 & sel_and_nand) | (~sel2 & sel_or_nor);
endmodule

// Exercício 04 - Seletor entre OR/NOR e XOR/XNOR
module Guia_0704 (
    input A, B,
    input [1:0] sel,
    output S
);
    wire or_out, nor_out, xor_out, xnor_out;
    or (or_out, A, B);
    nor (nor_out, A, B);
    xor (xor_out, A, B);
    xnor (xnor_out, A, B);
    assign S = (sel[1] & sel[0] & nor_out) | (sel[1] & ~sel[0] & or_out) | 
               (~sel[1] & sel[0] & xor_out) | (~sel[1] & ~sel[0] & xnor_out);
endmodule

// Exercício 05 - Seletor entre 7 operações
module Guia_0705 (
    input A, B,
    input [2:0] sel,
    output S
);
    wire not_out, and_out, nand_out, or_out, nor_out, xor_out, xnor_out;
    not (not_out, A);
    and (and_out, A, B);
    nand (nand_out, A, B);
    or (or_out, A, B);
    nor (nor_out, A, B);
    xor (xor_out, A, B);
    xnor (xnor_out, A, B);
    assign S = (sel[2] & sel[1] & sel[0] & xnor_out) | (sel[2] & sel[1] & ~sel[0] & xor_out) |
               (sel[2] & ~sel[1] & sel[0] & nor_out) | (sel[2] & ~sel[1] & ~sel[0] & or_out) |
               (~sel[2] & sel[1] & sel[0] & nand_out) | (~sel[2] & sel[1] & ~sel[0] & and_out) |
               (~sel[2] & ~sel[1] & ~sel[0] & not_out);
endmodule

// Exercício 06 - Comparador de Igualdade/Desigualdade com XOR/XNOR
module Guia_0706 (
    input [3:0] A, B,
    input sel,
    output S
);
    wire [3:0] xor_out, xnor_out;
    assign xor_out = A ^ B;
    assign xnor_out = ~(A ^ B);
    assign S = (sel & xnor_out[0] & xnor_out[1] & xnor_out[2] & xnor_out[3]) | 
               (~sel & (xor_out[0] | xor_out[1] | xor_out[2] | xor_out[3]));
endmodule

// Exercício 07 - Comparador de Magnitude usando apenas NOT, AND, OR
module Guia_0707 (
    input [3:0] A, B,
    input sel,
    output S
);
    wire [3:0] greater, lesser;
    assign greater[3] = A[3] & ~B[3];
    assign greater[2] = (A[3] ~^ B[3]) & (A[2] & ~B[2]);
    assign greater[1] = (A[3] ~^ B[3]) & (A[2] ~^ B[2]) & (A[1] & ~B[1]);
    assign greater[0] = (A[3] ~^ B[3]) & (A[2] ~^ B[2]) & (A[1] ~^ B[1]) & (A[0] & ~B[0]);
    assign lesser[3] = ~A[3] & B[3];
    assign lesser[2] = (A[3] ~^ B[3]) & (~A[2] & B[2]);
    assign lesser[1] = (A[3] ~^ B[3]) & (A[2] ~^ B[2]) & (~A[1] & B[1]);
    assign lesser[0] = (A[3] ~^ B[3]) & (A[2] ~^ B[2]) & (A[1] ~^ B[1]) & (~A[0] & B[0]);
    assign S = (sel & (greater[3] | greater[2] | greater[1] | greater[0])) | 
               (~sel & (lesser[3] | lesser[2] | lesser[1] | lesser[0]));
endmodule
