var vueinst = new Vue({
    el: '#account',
    data: {
        months: [
            {name:'January', dates:'4'},
            {name:'March', dates:'2'},
            {name:'May', dates:'1'},
            {name:'July', dates:'3'}
        ],
        dates: [1,2,3,4,5,5,6,23,12,22],
        name:'enter name',
        currentSelected: [false,false,false,false,false,false,false,false,false,false],
        other:[
            {name:'mary', selected:[true,false,true,false,true,false,true,true,false,true]},
            {name:'anne', selected:[false,true,true,false,false,false,false,false,false,true]},
            {name:'john', selected:[true,true,false,true,true,false,true,false,true,true]},
        ],
    },
    methods:{
        changet: function(n){
            this.currentSelected= [true,false,true,false,true,false,true,true,false,true];
        },
        changef: function(n){
            this.currentSelected = [false,true,true,false,false,false,false,false,false,true];
        }
    }
});