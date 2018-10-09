using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerVisible : MonoBehaviour {

	public GameObject player;
	public bool isSurveillanceCamera = false;
	public float viewRange;

	float viewAngle;
	// Use this for initialization
	void Start () {
		viewAngle = GetComponent<Light>().spotAngle;
	}
	
	// Update is called once per frame
	void Update () {
		if (isPlayerVisible())
		{
			if (isSurveillanceCamera)
				Detection.dt.visibilityLevel += 8 * Time.deltaTime;
			else
				Detection.dt.visibilityLevel += 4 * Time.deltaTime;
		}
	}

	bool isPlayerVisible()
	{
		if (Vector3.Angle(transform.forward, player.transform.position - transform.position) < viewAngle / 2)
		{
			if (Physics.Raycast(transform.position, player.transform.position - transform.position, viewRange))
				return true;
		}
		return false;
	}

	public Vector3 DirectionFromAngle(float angle, bool global)
	{
		if (!global)
			angle += transform.eulerAngles.y;
		return new Vector3(Mathf.Sin(angle * Mathf.Deg2Rad), -Mathf.Cos(angle * Mathf.Deg2Rad), 0);
	}
}
