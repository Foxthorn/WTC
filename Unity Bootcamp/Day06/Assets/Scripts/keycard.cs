using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class keycard : MonoBehaviour {

	bool isPickedUp = false;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (isPickedUp)
			gameObject.SetActive(false);
	}

	void OnTriggerEnter(Collider col)
	{
		if (col.transform.tag == "MainCamera")
		{
			isPickedUp = true;
			cameraMovement.cm.holdingKeycard = true;
		}
	}
}
