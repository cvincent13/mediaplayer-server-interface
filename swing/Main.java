
public class Main {

	private static final long serialVersionUID = 1L;
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;



	///
	/// Lit une requete depuis le Terminal, envoie cette requete au serveur,
	/// recupere sa reponse et l'affiche sur le Terminal.
	/// Noter que le programme bloque si le serveur ne repond pas.
	///

	public static void main(String argv[]) {
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;
		if (argv.length >=1) host = argv[0];
		if (argv.length >=2) port = Integer.parseInt(argv[1]);

		Client client = null;

		try {
			client = new Client(host, port);
		}
		catch (Exception e) {
			System.err.println("Client: Couldn't connect to "+host+":"+port);
			System.exit(1);
		}

		System.out.println("Client connected to "+host+":"+port);
		RemoteControl remoteControl = new RemoteControl();


		while (true) {
			// On récupère la requète chez l'interface
			String request = remoteControl.getRequest();

			// Si une requète est présente
			if (!request.isEmpty()) {
				// On affiche et envoie la requète au client
				System.out.println("Request: " + request);
				String response = client.send(request);

				// Affichage du résultat de la requète
				System.out.println("Response: " + response);
				remoteControl.writeLine(response);

				// On supprime la requète actuelle après qu'elle soit traitée
				remoteControl.newRequest("");
			}
			else {
				System.out.println("Waiting for request ...");
			}
		}
	}

}
