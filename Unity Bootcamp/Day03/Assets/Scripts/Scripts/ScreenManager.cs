using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class ScreenManager : MonoBehaviour {

	public GameObject pauseMenu;
	public GameObject confirmMenu;
	public GameObject scoreMenu;
	public static List<GameObject> towers = new List<GameObject>();
	public List<GameObject> levels = new List<GameObject>();
	int currentLevel = 0;

	void Start () {
		levels[currentLevel].SetActive(true);
		DeactivateOtherLevels();
		pauseMenu.SetActive(false);
		confirmMenu.SetActive(false);
		scoreMenu.SetActive(false);
	}

	void DeactivateOtherLevels()
	{
		for(int i = 0; i < levels.Count; i++)
		{
			if (i == currentLevel)
				continue;
			levels[i].SetActive(false);
		}
	}
	
	// Update is called once per frame
	void Update () {
		// if (Input.GetKeyDown("enter"))
		// 	gameManager.gm.finished = true;
		if (Input.GetKeyDown("escape"))
			LoadPauseMenu();
		if (gameManager.gm.finished)
		{
			if (gameManager.gm.playerHp > 0)
				EndMenu.gameWon = true;
			else
				EndMenu.gameWon = false;
			var script = scoreMenu.GetComponent<EndMenu>();
			scoreMenu.SetActive(true);
			script.Show();
		}
	}

	public void Resume()
	{
		BuyTower.paused = false;
		pauseMenu.SetActive(false);
		gameManager.gm.pause(false);
	}

	public void LoadPauseMenu()
	{
		BuyTower.paused = true;
		gameManager.gm.pause(true);
		pauseMenu.SetActive(true);
		confirmMenu.SetActive(false);
	}

	public void ConfirmQuit()
	{
		pauseMenu.SetActive(false);
		confirmMenu.SetActive(true);
	}

	public void LoadMainMenu()
	{
		SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex - 1);
	}

	public void Restart()
	{
		Scene scene = SceneManager.GetActiveScene();
		SceneManager.LoadScene(scene.name);
	}

	public void NextLevel()
	{
		for(int i = towers.Count - 1; i >= 0; i--)
		{
			Destroy(towers[i]);
		}
		currentLevel += 1;
		scoreMenu.SetActive(false);
		levels[1].SetActive(true);
		DeactivateOtherLevels();
		gameManager.gm.finished = false;
	}
}
