import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;

public class RemoteControl extends JFrame {
	private static final long serialVersionUID = 1L;

	private JTextArea textArea;
	private JButton button1;
	private JButton button2;
	private JButton button3;
	private JButton button4;
	private String request;

	///
	/// Accesseur de la requète actuelle
	///
	public String getRequest() {
		return request;
	}

	///
	/// Modifieur de la requète actuelle
	///
	public void newRequest(String request) {
		this.request = request;
	}

	///
	/// Interface de la télécommande
	///
	public RemoteControl() {
		request = "";

		setLayout(new BorderLayout());

		// Zone de texte
		textArea = new JTextArea(10, 40);
		textArea.setEditable(false);

		// Bouttons
		button1 = new JButton("Display group");
		button2 = new JButton("Display media");
		button3 = new JButton("Play media");
		button4 = new JButton("Exit");

		// Actions des bouttons
		button1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String name = JOptionPane.showInputDialog(null, "Enter name: ");
				request = "displayGroup " + name;
			}
		});

		button2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String name = JOptionPane.showInputDialog(null, "Enter name: ");
				request = "displayMedia " + name;
			}
		});

		button3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				String name = JOptionPane.showInputDialog(null, "Enter name: ");
				request = "play " + name;
			}
		});

		button4.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});

		JPanel buttonPanel = new JPanel();
		buttonPanel.add(button1);
		buttonPanel.add(button2);
		buttonPanel.add(button3);
		buttonPanel.add(button4);

		// Scroll pane pour la zone de texte
		JScrollPane scrollPane = new JScrollPane(textArea);

		add(scrollPane, BorderLayout.CENTER);
		add(buttonPanel, BorderLayout.SOUTH);

		// Barre de menu
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);

		JMenu menu = new JMenu("Actions");
		menuBar.add(menu);

		// Actions de la barre de menu
		menu.add(new DisplayGroupAction("Display Group"));
		menu.add(new DisplayMediaAction("Display Media"));
		menu.add(new PlayMediaAction("Play media"));
		menu.add(new ExitAction());

		// Barre d'outils
		JToolBar toolBar = new JToolBar();
		add(toolBar, BorderLayout.NORTH);

		// Actions de la barre d'outils
		toolBar.add(new DisplayGroupAction("Display Group"));
		toolBar.add(new DisplayMediaAction("Display Media"));
		toolBar.add(new PlayMediaAction("Play media"));
		toolBar.add(new ExitAction());

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		pack();
		setVisible(true);
	}

	///
	/// Fonction pour écrire sur la zone de texte
	///
	public void writeLine(String message) {
		textArea.append(message + "\n");
	}

	///
	/// Action pour les requètes d'affichage de médias
	///
	private class DisplayMediaAction extends AbstractAction {
		public DisplayMediaAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String name = JOptionPane.showInputDialog(null, "Enter media name: ");
			request = "displayMedia " + name;
		}
	}

	///
	/// Action pour les requètes d'affichage de groupes
	///
	private class DisplayGroupAction extends AbstractAction {
		public DisplayGroupAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String name = JOptionPane.showInputDialog(null, "Enter group name: ");
			request = "displayGroup " + name;
		}
	}

	///
	/// Action pour les requètes pour jouer les médias
	///
	private class PlayMediaAction extends AbstractAction {
		public PlayMediaAction(String name) {
			super(name);
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			String name = JOptionPane.showInputDialog(null, "Enter media name: ");
			request = "play " + name;
		}
	}

	///
	/// Action pour quitter l'interface
	///
	private class ExitAction extends AbstractAction {
		public ExitAction() {
			super("Exit");
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}
	}

}
