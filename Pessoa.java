public class Pessoa {
  String nome;
  String telefone;

  Pessoa(){}

  void inserirNome(String nomeParticipante) {
    nome = nomeParticipante;
  }
  void inserirTelefone(String telefoneParticipante) {
    telefone = telefoneParticipante;
  }
  String obterNome() {
    return nome;
  }
  String obterTelefone() {
    return telefone;
  }
}
