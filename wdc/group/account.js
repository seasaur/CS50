var vueinst = new Vue({
    el: '#account',
    data: {
        username: 'EpicUserName',
        email: 'EpicUserName@example.com',
        password: 'canBeHacked',
        events: [
            { name:'Event1', url:'' },
            { name:'Event2', url:'' },
            { name:'Event3', url:'' },
        ],
    }
});