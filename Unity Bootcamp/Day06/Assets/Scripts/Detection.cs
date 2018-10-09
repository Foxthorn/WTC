using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Detection : MonoBehaviour {
	public static Detection dt;
	public AudioClip clip;
	public float visibilityLevel = 0f;

	List<Image> panels = new List<Image>();
	AudioSource audio;
	bool soundPlaying = false;

	void Start()
	{
		if (dt == null)
			dt = this;
		audio = GetComponent<AudioSource>();
		foreach(Transform child in transform)
			panels.Add(child.gameObject.GetComponent<Image>());
	}

	void Update () {
		visibilityLevel = Mathf.Clamp(visibilityLevel, 0, 35);
		if (visibilityLevel == panels.Count - 1)
			Restart();
		else if (visibilityLevel / panels.Count >= 0.75f && !soundPlaying)
			Panic();
		else if (visibilityLevel / panels.Count < 0.7f)
		{
			audio.Stop();
			soundPlaying = false;
		}
		if (visibilityLevel != 0)
		{
			for (int i = 0; i < visibilityLevel; i++)
			{
				var temp = panels[i].color;
				temp.a = 0.39f;
				panels[i].color = temp;
			}
		}
		for (int i = panels.Count - 1; i >= visibilityLevel; i--)
		{
			var temp = panels[i].color;
			temp.a = 0.0f;
			panels[i].color = temp;
		}
		visibilityLevel -= 1 * Time.deltaTime;
	}

	void Panic()
	{
		audio.PlayOneShot(clip);
		soundPlaying = true;
	}

	void Restart()
	{
		Scene scene = SceneManager.GetActiveScene();
		SceneManager.LoadScene(scene.name);
	}

}
