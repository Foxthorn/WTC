using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EndMenu : MonoBehaviour {

	public static bool gameWon = false;

	string rank;

	public void Show()
	{
		GenerateRank();
		DisplayRank();
		DisplayScore();
		gameObject.transform.GetChild(3).gameObject.SetActive(!gameWon);
		gameObject.transform.GetChild(4).gameObject.SetActive(gameWon);
	}

	void DisplayRank()
	{
		var displayRank = gameObject.transform.GetChild(1).GetChild(0).gameObject;
		var text = displayRank.GetComponent<Text>();
		text.text = rank;
	}

	void DisplayScore()
	{
		var displayScore = gameObject.transform.GetChild(2).GetChild(1).GetChild(0).gameObject;
		var text = displayScore.GetComponent<Text>();
		string score = gameManager.gm.score.ToString();
		text.text = score;
	}

	void GenerateRank()
	{
		if (gameManager.gm.playerHp == gameManager.gm.playerMaxHp && gameManager.gm.playerEnergy > 500)
			rank = "S";
		else if (gameManager.gm.playerHp == gameManager.gm.playerMaxHp)
			rank = "A";
		else if (gameManager.gm.currentWave == 10)
			rank = "B";
		else if (gameManager.gm.currentWave > 8)
			rank = "C";
		else if (gameManager.gm.currentWave > 6)
			rank = "D";
		else if (gameManager.gm.currentWave > 4)
			rank = "E";
		else
			rank = "F";
	}
}
