document.addEventListener('DOMContentLoaded', function() {
    document.querySelector('form').addEventistener('submit', function(event) {
        let name = document.querySelector('#name').value;
        alert('hello, ' + name);
        event.preventDefault();
    });
});