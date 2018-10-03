using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameController : MonoBehaviour {

	public List<GameObject> units = new List<GameObject>();
	public List<Movement> scripts = new List<Movement>();
	public GameObject unit;
	public Transform location;
	// Use this for initialization
	void Start () {
		InvokeRepeating("Spawn", 10.0f, 10.0f);
		for(int i = 0; i < units.Count; i++)
		{
			var script = units[i].GetComponent<Movement>();
			scripts.Add(script);
		}
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown(KeyCode.Mouse0) && Input.GetKey(KeyCode.LeftControl))
		{
			var target = Camera.main.ScreenToWorldPoint(Input.mousePosition);
			for(int i = 0; i < units.Count; i++)
			{
				var dist = Vector2.Distance(target, units[i].transform.position);
				if (dist < 0.5)
				{
					scripts[i].selected = true;
					break;
				}
			}
		}
		else if (Input.GetKeyDown(KeyCode.Mouse0))
		{
			var target = Camera.main.ScreenToWorldPoint(Input.mousePosition);
			for(int i = 0; i < units.Count; i++)
			{
				var dist = Vector2.Distance(target, units[i].transform.position);
				if (dist < 0.5)
				{
					scripts[i].selected = true;
					UnselectOthers(i);
					break;
				}
			}
		}
		else if (Input.GetKeyDown(KeyCode.Mouse1))
		{
			UnselectAll();
		}
	}

	void UnselectOthers(int j)
	{
		for(int i = 0; i < scripts.Count; i++)
		{
			if (j == i)
				continue;
			scripts[i].selected = false;
		}
	}

	void UnselectAll()
	{
		for(int i = 0; i < scripts.Count; i++)
		{
			scripts[i].selected = false;
		}
	}

	void Spawn()
	{
		GameObject obj = (GameObject)Instantiate(unit, location.position, Quaternion.identity);
		units.Add(obj);
		var script = obj.GetComponent<Movement>();
		scripts.Add(script);
	}
}
