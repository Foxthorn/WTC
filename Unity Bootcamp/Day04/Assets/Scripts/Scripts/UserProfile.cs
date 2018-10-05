using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UserProfile : MonoBehaviour {

	public List<int> unlockedLevels = new List<int>();
	public int[] score = new int[6];
	public int numberOfDeaths;
	public int totalCoins;

	string	user;
	bool	display = true;
	bool	showingTitleScreen = true;
	IEnumerator	routine = null;

	public static UserProfile up;

	void Awake()
	{
		if (up == null)
			up = this;
	}

	void Start () {
		routine = DisplayGameStart(0.5f);
		StartCoroutine(routine);
		if (score.Length == 0)
			score = new int[6];
			
		gameObject.transform.GetChild(0).GetChild(1).gameObject.SetActive(false);
		int count = PlayerPrefs.GetInt("unlockedLevels_Count");
		for (int i = 0; i < count; i++)
		{
			unlockedLevels.Add(PlayerPrefs.GetInt("unlockedLevels_" + i));
		}
		for (int i = 0; i < 6; i++)
		{
			score[i] = PlayerPrefs.GetInt("score_" + i);
		}
		totalCoins = PlayerPrefs.GetInt("totalCoins");
		numberOfDeaths = PlayerPrefs.GetInt("numberOfDeaths");
		if (unlockedLevels.Count == 0)
			unlockedLevels.Add(0);
	}

	void Update() {
		if (Input.GetKeyDown("return"))
			LoadDataSelectScreen();
	}

	public void LoadDataSelectScreen()
	{
		showingTitleScreen = false;
		StopCoroutine(routine);
		SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);

	}

	IEnumerator DisplayGameStart(float time)
	{
		while(showingTitleScreen)
		{
			gameObject.transform.GetChild(0).GetChild(2).gameObject.SetActive(display);
			display = !display;
			yield return new WaitForSeconds(time);
		}
	}

	public void Reset()
	{
		PlayerPrefs.DeleteAll();
		unlockedLevels.Clear();
		unlockedLevels.Add(0);
		for (int i = 0; i < score.Length; i++)
			score[i] = 0;
		numberOfDeaths = 0;
		gameObject.transform.GetChild(0).GetChild(1).gameObject.SetActive(true);
	}

	void SaveUnlockedLevels()
	{
		PlayerPrefs.SetInt("unlockedLevels_Count", unlockedLevels.Count);
		for(int i = 0; i < unlockedLevels.Count; i++)
		{
			PlayerPrefs.SetInt("unlockedLevels_" + i, unlockedLevels[i]);
		}
	}

	void SaveScore()
	{
		for(int i = 0; i < 6; i++)
		{
			PlayerPrefs.SetInt("score_" + i, score[i]);
		}
	}

	public void Save()
	{
		SaveUnlockedLevels();
		SaveScore();
		PlayerPrefs.SetInt("totalCoins", totalCoins);
		PlayerPrefs.SetInt("numberOfDeaths", numberOfDeaths);
		PlayerPrefs.Save();
	}
}
