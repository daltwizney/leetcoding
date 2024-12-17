console.log('moar leetcoding!');

class Node {

    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
	// CREATE LL CONSTRUCTOR HERE //
	//                            //
	//                            //
	//                            //
	//                            //
	////////////////////////////////
    constructor(value) {

        let newNode = new Node(value);

        this.head = newNode;
        this.tail = newNode;
        this.length = 1;
    }

    printList() {
        let temp = this.head;
        while (temp !== null) {
            console.log(temp.value);
            temp = temp.next;
        }
    }

    getHead() {
        if (this.head === null) {
            console.log("Head: null");
        } else {
            console.log("Head: " + this.head.value);
        }
    }

    getTail() {
        if (this.head === null) {
            console.log("Tail: null");
        } else {
            console.log("Tail: " + this.tail.value);
        }
    }

    getLength() {
        console.log("Length: " + this.length);
    }

    push(value) {

        if (this.length === 0)
        {
            this.head = new Node(value);
            this.tail = this.head;
            this.length = 1;
            return;
        }

        let temp = this.tail;
        temp.next = new Node(value);

        this.tail = temp.next;

        this.length++;
    }

    pop() {

        if (this.length === 0)
        {
            return undefined;
        }

        if (this.length === 1)
        {
            let temp = this.head;

            this.head = null;
            this.tail = null;
            this.length = 0;

            return temp;
        }

        let temp = this.head;

        while (temp.next && temp.next.next)
        {
            temp = temp.next;
        }

        let removedNode = temp.next;

        this.tail = temp;
        this.tail.next = null;

        this.length--;

        return removedNode;
    }

    unshift(value) {

        if (this.length === 0)
        {
            this.head = new Node(value);
            this.tail = this.head;
            this.length++;
            return this;
        }

        let temp = this.head;

        this.head = new Node(value);
        this.head.next = temp;

        this.length++;

        return this;
    }

    shift() {

        if (this.length === 0)
        {
            return null;
        }

        let temp = this.head;

        this.head = temp.next;

        if (!this.head)
        {
            this.tail = null;
        }

        this.length--;

        return temp;
    }
    
    get(index) {

        if (index < 0 || index >= this.length)
        {
            return undefined;
        }

        let temp = this.head;

        for (let i = 1; i <= index; ++i)
        {
            temp = temp.next;
        }

        return temp;
    }

    set(index, value) {

        let node = this.get(index);

        if (node)
        {
            node.value = value;
            return true;
        }

        return false;
    }

    insert(index, value) {

        if (index == 0 || this.length == 0)
        {
            this.unshift(value);
            return true;
        }

        if (index < 0 || index > this.length)
        {
            return false;
        }

        let previous = this.get(index - 1);

        let temp = previous.next;

        previous.next = new Node(value);

        previous.next.next = temp;

        this.length++;

        return true;
    }

    remove(index) {

        if (index == 0)
        {
            return this.shift();
        }

        if (index < 0 || index >= this.length || this.length === 0)
        {
            return null;
        }

        let previous = this.get(index - 1);

        let temp = previous.next;

        previous.next = temp.next;

        this.length--;

        return temp;
    }

    reverse() {

        
    }
}