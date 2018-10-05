using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class BuyTower : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler {

	public static GameObject itemDrag;
	public GameObject tower;
	public Sprite towerSprite;
	public Sprite notEnoughEnergy;
	public static bool paused;

	Vector3 startPosition;
	Image image;
	towerScript towerScript;
	bool canBeDragged;

	public void Start()
	{
	    canBeDragged = false;
		towerScript = tower.GetComponent<towerScript>();
		image = GetComponent<Image>();
	}

	public void OnBeginDrag(PointerEventData eventData)
	{
		if (canBeDragged && !paused)
		{
			itemDrag = Instantiate(tower, transform);
			startPosition = transform.position;
		}
	}

	public void OnDrag(PointerEventData eventData)
	{
		if (canBeDragged && !paused)
			transform.position = Input.mousePosition;
	}

	public void OnEndDrag(PointerEventData eventData)
	{
		if (itemDrag != null && canBeDragged && !paused)
		{
			RaycastHit2D hit = Physics2D.Raycast (Camera.main.ScreenToWorldPoint (Input.mousePosition), Vector2.zero);
			if (hit && hit.collider.transform.tag == "empty" && (gameManager.gm.playerEnergy - towerScript.energy) > 0)
			{
				var placeTower = (GameObject)Instantiate(tower, hit.collider.gameObject.transform.position, Quaternion.identity);
				ScreenManager.towers.Add(placeTower);			
				gameManager.gm.playerEnergy -= towerScript.energy;
			}
			transform.position = startPosition;
			Destroy(itemDrag);
			itemDrag = null;
		}
	}

	public void Update()
	{
		if ((gameManager.gm.playerEnergy - towerScript.energy) <= 0)
		{
			image.sprite = notEnoughEnergy;
			canBeDragged = false;
		}
		else
		{
			image.sprite = towerSprite;
			canBeDragged = true;
		}
	}
}
