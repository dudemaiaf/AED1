import javax.swing.JOptionPane;
public class SorteioGanhador {
  public static void main(String[] args){
    Pessoa[] participantes = new Pessoa[10];

    for(int i = 0; i < 10; i ++){
      Pessoa participante = new Pessoa();
      String nome = JOptionPane.showInputDialog("Forneça o nome da pessoa " + (int)(i+1) + ": ");
      participante.inserirNome(nome);
      String telefone = JOptionPane.showInputDialog("Forneça o telefone da pessoa " + (int)(i+1) + ": ");
      participante.inserirTelefone(telefone);
      participantes[i] = participante;
      if(participantes[i] == null){
        System.exit(0);
      }
    }
    int numeroSorteado = (int)(Math.random()*10);
    JOptionPane.showMessageDialog(null, "Nome do ganhador: " + participantes[numeroSorteado].obterNome() + "\nTelefone do ganhador: " + participantes[numeroSorteado].obterTelefone() );

    System.exit(0);
  }
}
