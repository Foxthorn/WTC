using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DataSelect : MonoBehaviour {

	public List<GameObject> levels;

	int selected = 0;

	// Use this for initialization
	void Start () {
		var lives = gameObject.transform.GetChild(0).GetChild(0).GetChild(1).gameObject.GetComponent<Text>();
		lives.text = "x " + UserProfile.up.numberOfDeaths;

		var coins = gameObject.transform.GetChild(0).GetChild(0).GetChild(3).gameObject.GetComponent<Text>();
		coins.text = "x " + UserProfile.up.totalCoins;

		setAvailable();
		setSelected();
	}
	
	// Update is called once per frame
	void Update () {
		setSelected();
		UpdateLevelName();
		UpdateBestScore();
		if (Input.GetKeyDown(KeyCode.RightArrow))
		{
			selected += 1;
			if (selected > 5)
				selected = 0;
		}
		if (Input.GetKeyDown(KeyCode.LeftArrow))
		{
			selected -= 1;
			if (selected < 0)
				selected = 5;
		}
		if (Input.GetKeyDown(KeyCode.UpArrow) || Input.GetKeyDown(KeyCode.DownArrow))
		{
			if (selected < 3)
				selected += 3;
			else
				selected -= 3;
		}
		if (Input.GetKeyDown("escape"))
		{
			UserProfile.up.Save();
			Application.Quit();
		}
	}

	void UpdateBestScore()
	{
		var score = "Best Score: " + UserProfile.up.score[selected].ToString();
		var bestScore = gameObject.transform.GetChild(0).GetChild(1).GetChild(1).GetChild(0).gameObject.GetComponent<Text>();
		bestScore.text = score;
	}

	void UpdateLevelName()
	{
		var name = levels[selected].transform.GetChild(1).GetChild(0).gameObject.GetComponent<Text>().text;
		var levelName = gameObject.transform.GetChild(0).GetChild(1).GetChild(0).GetChild(0).gameObject.GetComponent<Text>();
		levelName.text = name;
	}

	void setAvailable()
	{
		for(int i = 0; i < UserProfile.up.unlockedLevels.Count; i++)
		{
			if (i == UserProfile.up.unlockedLevels[i])
				levels[i].transform.GetChild(1).GetChild(2).gameObject.SetActive(false);
			else
				levels[i].transform.GetChild(1).GetChild(2).gameObject.SetActive(true);
		}
	}

	void setSelected()
	{
		for(int i = 0; i < levels.Count; i++)
		{
			if (i == selected)
				levels[i].transform.GetChild(0).gameObject.SetActive(true);
			else
				levels[i].transform.GetChild(0).gameObject.SetActive(false);
		}
	}
}
