package app;

import java.util.List;
import java.util.Scanner;

import dao.UsuarioDAO;
import model.Usuario;

public class Aplicacao {

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        UsuarioDAO usuarioDAO = new UsuarioDAO();
        int opcao;
        
        do {
            System.out.println("\n=== MENU CRUD ===");
            System.out.println("1 - Listar usuários");
            System.out.println("2 - Inserir usuário");
            System.out.println("3 - Excluir usuário");
            System.out.println("4 - Atualizar usuário");
            System.out.println("5 - Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine(); // Limpa buffer

            switch (opcao) {
                case 1:
                    listarUsuarios(usuarioDAO);
                    break;
                case 2:
                    inserirUsuario(scanner, usuarioDAO);
                    break;
                case 3:
                    excluirUsuario(scanner, usuarioDAO);
                    break;
                case 4:
                    atualizarUsuario(scanner, usuarioDAO);
                    break;
                case 5:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção inválida!");
            }
        } while (opcao != 5);
        
        scanner.close();
    }

    private static void listarUsuarios(UsuarioDAO usuarioDAO) {
        System.out.println("\n=== Lista de Usuários ===");
        List<Usuario> usuarios = usuarioDAO.getOrderByCodigo();
        for (Usuario u : usuarios) {
            System.out.println(u);
        }
    }

    private static void inserirUsuario(Scanner scanner, UsuarioDAO usuarioDAO) {
        System.out.print("Digite o código: ");
        int codigo = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Digite o login: ");
        String login = scanner.nextLine();
        System.out.print("Digite a senha: ");
        String senha = scanner.nextLine();
        System.out.print("Digite o sexo (M/F): ");
        char sexo = scanner.next().charAt(0);
        
        Usuario usuario = new Usuario(codigo, login, senha, sexo);
        if (usuarioDAO.insert(usuario)) {
            System.out.println("Usuário inserido com sucesso!");
        } else {
            System.out.println("Erro ao inserir usuário.");
        }
    }

    private static void excluirUsuario(Scanner scanner, UsuarioDAO usuarioDAO) {
        System.out.print("Digite o código do usuário a ser excluído: ");
        int codigo = scanner.nextInt();
        if (usuarioDAO.delete(codigo)) {
            System.out.println("Usuário excluído com sucesso!");
        } else {
            System.out.println("Erro ao excluir usuário.");
        }
    }

    private static void atualizarUsuario(Scanner scanner, UsuarioDAO usuarioDAO) {
        System.out.print("Digite o código do usuário a ser atualizado: ");
        int codigo = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Digite o novo login: ");
        String login = scanner.nextLine();
        System.out.print("Digite a nova senha: ");
        String senha = scanner.nextLine();
        System.out.print("Digite o novo sexo (M/F): ");
        char sexo = scanner.next().charAt(0);
        
        Usuario usuario = new Usuario(codigo, login, senha, sexo);
        if (usuarioDAO.update(usuario)) {
            System.out.println("Usuário atualizado com sucesso!");
        } else {
            System.out.println("Erro ao atualizar usuário.");
        }
    }
}
